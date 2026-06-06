#include <stdio.h>

/* A minimal push-based Observable implemented from scratch.
 * An observer is a callback that receives a value (next).
 * A "list" here is a fixed array each subscriber collects into. */

#define MAX_VALUES 8

typedef struct {
    int values[MAX_VALUES];
    int count;
} Sink;

static void sink_next(Sink *s, int v) {
    if (s->count < MAX_VALUES) {
        s->values[s->count++] = v;
    }
}

static void print_sink(const char *label, const Sink *s) {
    printf("%s:", label);
    for (int i = 0; i < s->count; i++) {
        printf(" %d", s->values[i]);
    }
    printf("\n");
}

/* COLD: subscribing runs the producer independently for each subscriber. */
static void cold_subscribe(Sink *s) {
    /* producer re-runs from scratch */
    sink_next(s, 1);
    sink_next(s, 2);
    sink_next(s, 3);
}

int main(void) {
    /* ---- Cold observable ---- */
    Sink coldA = {{0}, 0};
    Sink coldB = {{0}, 0};
    cold_subscribe(&coldA); /* A re-runs producer -> 1 2 3 */
    cold_subscribe(&coldB); /* B re-runs producer -> 1 2 3 */
    print_sink("cold A", &coldA);
    print_sink("cold B", &coldB);

    /* ---- Hot observable ---- */
    /* One shared producer; observers attached at subscribe time only
     * receive values emitted after they subscribe. */
    Sink hotA = {{0}, 0};
    Sink hotB = {{0}, 0};
    int hotA_active = 0;
    int hotB_active = 0;

    hotA_active = 1;               /* A subscribes first            */
    if (hotA_active) sink_next(&hotA, 1); /* producer emits 1 (only A) */
    hotB_active = 1;               /* B subscribes (misses earlier) */
    if (hotA_active) sink_next(&hotA, 2); /* emit 2 to both          */
    if (hotB_active) sink_next(&hotB, 2);
    if (hotA_active) sink_next(&hotA, 3); /* emit 3 to both          */
    if (hotB_active) sink_next(&hotB, 3);

    print_sink("hot A", &hotA);
    print_sink("hot B", &hotB);

    return 0;
}
