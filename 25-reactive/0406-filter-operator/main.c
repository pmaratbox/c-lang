#include <stdio.h>
#include <stdbool.h>

/* A push-based observer: a callback plus its context. */
typedef struct {
    void (*next)(void *ctx, int value);
    void *ctx;
} Observer;

typedef bool (*Predicate)(int value);

/* Filter operator: holds the downstream observer and a predicate. */
typedef struct {
    Observer downstream;
    Predicate pred;
} FilterCtx;

/* Forward a value only when pred(value) is true. */
static void filter_next(void *ctx, int value) {
    FilterCtx *fc = (FilterCtx *)ctx;
    if (fc->pred(value)) {
        fc->downstream.next(fc->downstream.ctx, value);
    }
}

static void print_next(void *ctx, int value) {
    (void)ctx;
    printf("%d\n", value);
}

static bool is_even(int value) {
    return value % 2 == 0;
}

int main(void) {
    Observer sink = { .next = print_next, .ctx = NULL };
    FilterCtx fc = { .downstream = sink, .pred = is_even };
    Observer filtered = { .next = filter_next, .ctx = &fc };

    /* Source emits 1,2,3,4,5,6 synchronously into the filter. */
    int source[] = { 1, 2, 3, 4, 5, 6 };
    for (int i = 0; i < 6; i++) {
        filtered.next(filtered.ctx, source[i]);
    }

    return 0;
}
