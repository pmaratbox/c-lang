#include <stdio.h>

/* Virtual-time scheduler: fixed array of (time, seq, alive, callback). */

#define MAX_EVENTS 64

typedef void (*Callback)(int arg);

typedef struct {
    int time;
    int seq;
    int alive;
    Callback cb;
    int arg;
} Event;

static Event events[MAX_EVENTS];
static int event_count = 0;
static int seq_counter = 0;
static int now = 0;

/* schedule an event at absolute virtual time t; return its index as a token. */
static int schedule(int t, Callback cb, int arg) {
    int idx = event_count++;
    events[idx].time = t;
    events[idx].seq = seq_counter++;
    events[idx].alive = 1;
    events[idx].cb = cb;
    events[idx].arg = arg;
    return idx;
}

static void cancel(int token) {
    if (token >= 0 && token < event_count) {
        events[token].alive = 0;
    }
}

static void run(void) {
    for (;;) {
        int best = -1;
        for (int i = 0; i < event_count; i++) {
            if (!events[i].alive) continue;
            if (best == -1 ||
                events[i].time < events[best].time ||
                (events[i].time == events[best].time &&
                 events[i].seq < events[best].seq)) {
                best = i;
            }
        }
        if (best == -1) break;
        events[best].alive = 0;
        now = events[best].time;
        events[best].cb(events[best].arg);
    }
}

/* Inner observable: schedules (now+5 -> n) and (now+30 -> n*10).
 * We track the two pending tokens of the current inner so a new outer
 * value can cancel them (switchMap semantics). */

static int inner_tok_a = -1;
static int inner_tok_b = -1;

static void inner_next(int v) {
    printf("%d\n", v);
}

static void start_inner(int n) {
    /* cancel previous inner's still-pending emissions */
    cancel(inner_tok_a);
    cancel(inner_tok_b);
    inner_tok_a = schedule(now + 5, inner_next, n);
    inner_tok_b = schedule(now + 30, inner_next, n * 10);
}

int main(void) {
    /* outer: (10 -> 1), (20 -> 2) */
    schedule(10, start_inner, 1);
    schedule(20, start_inner, 2);
    run();
    return 0;
}
