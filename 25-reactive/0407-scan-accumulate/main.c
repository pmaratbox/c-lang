#include <stdio.h>

typedef void (*next_fn)(int value, void *ctx);

/* An observer is a next callback plus an opaque context. */
typedef struct {
    next_fn next;
    void *ctx;
} observer;

/* scan state: seed accumulator, fold function, and downstream observer. */
typedef struct {
    int state;
    int (*f)(int acc, int value);
    observer down;
} scan_state;

static int add(int acc, int value) {
    return acc + value;
}

/* scan operator: for each value, state = f(state, value) then emit state. */
static void scan_next(int value, void *ctx) {
    scan_state *s = (scan_state *)ctx;
    s->state = s->f(s->state, value);
    s->down.next(s->state, s->down.ctx);
}

static void print_next(int value, void *ctx) {
    (void)ctx;
    printf("%d\n", value);
}

/* source: pushes a fixed array of values into an observer. */
static void source_subscribe(const int *values, int n, observer obs) {
    for (int i = 0; i < n; i++) {
        obs.next(values[i], obs.ctx);
    }
}

int main(void) {
    const int values[] = {1, 2, 3, 4};
    const int n = (int)(sizeof(values) / sizeof(values[0]));

    observer sink = { print_next, NULL };
    scan_state st = { 0, add, sink };
    observer scanned = { scan_next, &st };

    source_subscribe(values, n, scanned);
    return 0;
}
