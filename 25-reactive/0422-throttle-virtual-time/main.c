#include <stdio.h>

/* Virtual-time scheduler: a fixed array of (time, seq, cb, alive) entries,
   popped in (time, seq) order. No real timers, no wall clock. */

#define MAX_EVENTS 16

typedef void (*event_fn)(const char *value);

typedef struct {
    int time;
    int seq;
    event_fn cb;
    const char *value;
    int alive;
} event_t;

static event_t events[MAX_EVENTS];
static int event_count = 0;
static int next_seq = 0;
static int now = 0;

static void schedule(int time, event_fn cb, const char *value) {
    event_t *e = &events[event_count++];
    e->time = time;
    e->seq = next_seq++;
    e->cb = cb;
    e->value = value;
    e->alive = 1;
}

static void run(void) {
    for (;;) {
        int best = -1;
        for (int i = 0; i < event_count; i++) {
            if (!events[i].alive)
                continue;
            if (best == -1 ||
                events[i].time < events[best].time ||
                (events[i].time == events[best].time &&
                 events[i].seq < events[best].seq)) {
                best = i;
            }
        }
        if (best == -1)
            break;
        events[best].alive = 0;
        now = events[best].time;
        events[best].cb(events[best].value);
    }
}

/* throttle(window), leading edge */
static int block_until = 0;
static const int window = 30;

static void on_value(const char *value) {
    if (now >= block_until) {
        printf("%s\n", value);
        block_until = now + window;
    }
}

int main(void) {
    schedule(10, on_value, "a");
    schedule(20, on_value, "b");
    schedule(100, on_value, "c");
    schedule(110, on_value, "d");
    run();
    return 0;
}
