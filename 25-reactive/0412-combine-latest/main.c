#include <stdio.h>

/* Virtual-time scheduler: a small fixed array of (time, seq, callback)
   sorted on pop by (time, seq). No real timers, no wall clock. */

typedef void (*Cb)(int value);

typedef struct {
    int  time;
    int  seq;
    Cb   cb;
    int  value;
    int  alive;
} Event;

#define MAX_EVENTS 16
static Event events[MAX_EVENTS];
static int   event_count = 0;
static int   next_seq = 0;
static int   vclock = 0;

static void schedule(int time, Cb cb, int value) {
    Event *e = &events[event_count++];
    e->time  = time;
    e->seq   = next_seq++;
    e->cb    = cb;
    e->value = value;
    e->alive = 1;
}

static void run(void) {
    for (;;) {
        int best = -1;
        for (int i = 0; i < event_count; i++) {
            if (!events[i].alive) continue;
            if (best < 0 ||
                events[i].time < events[best].time ||
                (events[i].time == events[best].time &&
                 events[i].seq  < events[best].seq)) {
                best = i;
            }
        }
        if (best < 0) break;
        events[best].alive = 0;
        vclock = events[best].time;
        events[best].cb(events[best].value);
    }
}

/* combineLatest state for two sources. */
static int has_a = 0, latest_a = 0;
static int has_b = 0, latest_b = 0;

static void emit_if_both(void) {
    if (has_a && has_b) {
        printf("(%d, %d)\n", latest_a, latest_b);
    }
}

static void on_a(int value) {
    has_a = 1;
    latest_a = value;
    emit_if_both();
}

static void on_b(int value) {
    has_b = 1;
    latest_b = value;
    emit_if_both();
}

int main(void) {
    /* Source A: (1->1), (3->2). Source B: (2->10). */
    schedule(1, on_a, 1);
    schedule(3, on_a, 2);
    schedule(2, on_b, 10);

    run();
    return 0;
}
