#include <stdio.h>

/* A tiny push-based Observable + virtual-time scheduler, from scratch.
 *
 * flatMap (mergeMap): each outer value is mapped to an inner timed stream,
 * and all inner streams run concurrently (no cancellation of earlier inners).
 *
 * Schedule (virtual clock):
 *   outer: 10 -> 1, 20 -> 2
 *   for each outer value n at time t:
 *       inner schedules (t+5 -> n) and (t+30 -> n*10)
 *   timeline: 15->1, 25->2, 40->10, 50->20  => 1, 2, 10, 20
 */

#define MAX_EVENTS 32

typedef struct {
    int time;       /* virtual time at which to fire */
    int seq;        /* insertion order, breaks ties at equal time */
    int value;      /* payload to emit */
    int kind;       /* 0 = outer event, 1 = inner event */
    int alive;      /* 1 if not cancelled / not yet run */
} Event;

static Event queue[MAX_EVENTS];
static int   queue_len = 0;
static int   next_seq  = 0;
static int   clock_now = 0;

static void schedule(int time, int value, int kind) {
    Event e;
    e.time  = time;
    e.seq   = next_seq++;
    e.value = value;
    e.kind  = kind;
    e.alive = 1;
    queue[queue_len++] = e;
}

/* The observer: receive a merged inner value and print it. */
static void on_next(int value) {
    printf("%d\n", value);
}

/* Map an outer value to its inner timed stream (concurrent). */
static void flat_map(int n) {
    schedule(clock_now + 5,  n,      1);
    schedule(clock_now + 30, n * 10, 1);
}

static void run(void) {
    for (;;) {
        int best = -1;
        for (int i = 0; i < queue_len; i++) {
            if (!queue[i].alive) continue;
            if (best == -1 ||
                queue[i].time < queue[best].time ||
                (queue[i].time == queue[best].time &&
                 queue[i].seq  < queue[best].seq)) {
                best = i;
            }
        }
        if (best == -1) break;        /* nothing left to run */

        queue[best].alive = 0;
        clock_now = queue[best].time; /* advance the virtual clock */

        if (queue[best].kind == 0) {
            flat_map(queue[best].value);
        } else {
            on_next(queue[best].value);
        }
    }
}

int main(void) {
    /* Outer source emits its values at virtual times 10 and 20. */
    schedule(10, 1, 0);
    schedule(20, 2, 0);

    run();
    return 0;
}
