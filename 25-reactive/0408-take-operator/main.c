#include <stdio.h>

/* A minimal push-based Observable, implemented from scratch.
 *
 * An observer is a set of callbacks (next/complete). A subscription
 * exposes an `active` flag the producer checks: unsubscribing clears it,
 * which stops an otherwise-infinite source from being driven further. */

typedef struct {
    int active;
} Subscription;

typedef struct {
    void (*next)(void *ctx, int value);
    void (*complete)(void *ctx);
    void *ctx;
} Observer;

/* Source: the natural numbers 1,2,3,... It keeps emitting only while
 * the subscription stays active, so a downstream operator can stop it. */
static void naturals_subscribe(Observer *obs, Subscription *sub) {
    sub->active = 1;
    int n = 1;
    while (sub->active) {
        obs->next(obs->ctx, n);
        n++;
    }
}

/* take(n): forward the first n emissions, then complete and unsubscribe
 * the source so it stops being driven. */
typedef struct {
    int limit;
    int taken;
    Observer *downstream;
    Subscription *source_sub;
} TakeState;

static void take_next(void *ctx, int value) {
    TakeState *st = (TakeState *)ctx;
    if (st->taken >= st->limit) return;
    st->downstream->next(st->downstream->ctx, value);
    st->taken++;
    if (st->taken >= st->limit) {
        st->downstream->complete(st->downstream->ctx);
        st->source_sub->active = 0; /* unsubscribe: stop the source */
    }
}

static void take_complete(void *ctx) {
    TakeState *st = (TakeState *)ctx;
    st->downstream->complete(st->downstream->ctx);
}

/* Terminal observer: print each value, and "completed" on completion. */
static void print_next(void *ctx, int value) {
    (void)ctx;
    printf("%d\n", value);
}

static void print_complete(void *ctx) {
    (void)ctx;
    printf("completed\n");
}

int main(void) {
    Observer sink = { print_next, print_complete, NULL };

    Subscription source_sub;
    TakeState st = { 3, 0, &sink, &source_sub };
    Observer take_obs = { take_next, take_complete, &st };

    naturals_subscribe(&take_obs, &source_sub);
    return 0;
}
