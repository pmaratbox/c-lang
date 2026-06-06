#include <stdio.h>

/* A push-based Observable built from scratch, driven by a virtual-time
 * scheduler: a small fixed array of (time, seq, callback) entries popped in
 * (time, seq) order. No real time, no threads, no randomness. */

typedef struct Observer {
    void (*next)(struct Observer *self, int value);
} Observer;

typedef struct {
    int time;
    int seq;
    int value;
    Observer *obs;
    int dead;
} Event;

#define MAX_EVENTS 16

static Event events[MAX_EVENTS];
static int event_count = 0;
static int seq_counter = 0;
static int virtual_clock = 0;

static void schedule(int time, int value, Observer *obs) {
    Event *e = &events[event_count++];
    e->time = time;
    e->seq = seq_counter++;
    e->value = value;
    e->obs = obs;
    e->dead = 0;
}

static void run(void) {
    for (;;) {
        int best = -1;
        for (int i = 0; i < event_count; i++) {
            if (events[i].dead) continue;
            if (best < 0 ||
                events[i].time < events[best].time ||
                (events[i].time == events[best].time &&
                 events[i].seq < events[best].seq)) {
                best = i;
            }
        }
        if (best < 0) break;
        Event *e = &events[best];
        e->dead = 1;
        virtual_clock = e->time;
        e->obs->next(e->obs, e->value);
    }
}

/* A source emits by scheduling its events at the given virtual times. */
static void source(const int *times, const int *values, int n, Observer *obs) {
    for (int i = 0; i < n; i++) {
        schedule(times[i], values[i], obs);
    }
}

static void print_next(Observer *self, int value) {
    (void)self;
    printf("%d\n", value);
}

int main(void) {
    Observer sink = { print_next };

    /* Stream A: (10->1),(30->3),(50->5)  Stream B: (20->2),(40->4),(60->6).
     * merge subscribes both onto the same observer. */
    int a_times[]  = {10, 30, 50};
    int a_values[] = {1, 3, 5};
    int b_times[]  = {20, 40, 60};
    int b_values[] = {2, 4, 6};

    source(a_times, a_values, 3, &sink);
    source(b_times, b_values, 3, &sink);

    run();
    return 0;
}
