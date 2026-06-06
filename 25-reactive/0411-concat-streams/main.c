#include <stdio.h>

/* A minimal push-based Observable implemented from scratch.
 * An observer has next/complete callbacks; subscribe wires a producer
 * to that observer. concat subscribes to the first source, and only
 * after it completes subscribes to the second. */

typedef struct {
    void (*next)(void *ctx, int value);
    void (*complete)(void *ctx);
    void *ctx;
} Observer;

typedef struct {
    void (*subscribe)(void *self, Observer *obs);
    const int *values;
    int count;
} Source;

/* A source emits each of its values then completes. */
static void source_subscribe(void *self, Observer *obs) {
    Source *src = (Source *)self;
    for (int i = 0; i < src->count; i++) {
        obs->next(obs->ctx, src->values[i]);
    }
    obs->complete(obs->ctx);
}

/* concat state: forward next from either source; when the first
 * completes, subscribe to the second; when the second completes,
 * signal completion to the downstream observer. */
typedef struct {
    Source *second;
    Observer downstream;
} ConcatCtx;

static void concat_next(void *ctx, int value) {
    ConcatCtx *c = (ConcatCtx *)ctx;
    c->downstream.next(c->downstream.ctx, value);
}

static void concat_second_complete(void *ctx) {
    ConcatCtx *c = (ConcatCtx *)ctx;
    c->downstream.complete(c->downstream.ctx);
}

static void concat_first_complete(void *ctx) {
    ConcatCtx *c = (ConcatCtx *)ctx;
    Observer inner = { concat_next, concat_second_complete, c };
    c->second->subscribe(c->second, &inner);
}

static void concat_subscribe(Source *a, Source *b, Observer *downstream) {
    ConcatCtx c = { b, *downstream };
    Observer inner = { concat_next, concat_first_complete, &c };
    a->subscribe(a, &inner);
}

/* Downstream observer simply prints each emitted value. */
static void print_next(void *ctx, int value) {
    (void)ctx;
    printf("%d\n", value);
}

static void print_complete(void *ctx) {
    (void)ctx;
}

int main(void) {
    static const int va[] = {1, 2};
    static const int vb[] = {3, 4};

    Source a = { source_subscribe, va, 2 };
    Source b = { source_subscribe, vb, 2 };

    Observer out = { print_next, print_complete, NULL };
    concat_subscribe(&a, &b, &out);

    return 0;
}
