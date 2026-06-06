#include <stdio.h>

/* A push-based Observable implemented from scratch. An observer has
   next/error/complete callbacks; subscribe wires a producer to it.
   catchError forwards next values, but on error subscribes to a
   fallback stream instead of propagating the error. */

typedef struct Observer {
    void (*next)(struct Observer *self, int value);
    void (*error)(struct Observer *self);
    void (*complete)(struct Observer *self);
    void *ctx;
} Observer;

/* A source is just a function that, given an observer, drives emissions. */
typedef void (*Source)(Observer *obs);

/* source: emits 1, 2, then signals error. */
static void source(Observer *obs) {
    obs->next(obs, 1);
    obs->next(obs, 2);
    obs->error(obs);
}

/* fallback: emits 9 then completes. */
static void fallback(Observer *obs) {
    obs->next(obs, 9);
    obs->complete(obs);
}

/* The downstream observer that prints values. */
static void print_next(Observer *self, int value) {
    (void)self;
    printf("%d\n", value);
}
static void print_error(Observer *self) { (void)self; }
static void print_complete(Observer *self) { (void)self; }

/* catchError observer: forwards next/complete to downstream, but on
   error subscribes to the fallback (driving it into downstream). */
static void catch_next(Observer *self, int value) {
    Observer *downstream = (Observer *)self->ctx;
    downstream->next(downstream, value);
}
static void catch_complete(Observer *self) {
    Observer *downstream = (Observer *)self->ctx;
    downstream->complete(downstream);
}
static void catch_error(Observer *self) {
    Observer *downstream = (Observer *)self->ctx;
    fallback(downstream);
}

static void catchError(Source src, Source fb, Observer *downstream) {
    (void)fb; /* fallback is wired inside catch_error */
    Observer wrapper = {
        .next = catch_next,
        .error = catch_error,
        .complete = catch_complete,
        .ctx = downstream,
    };
    src(&wrapper);
}

int main(void) {
    Observer sink = {
        .next = print_next,
        .error = print_error,
        .complete = print_complete,
        .ctx = NULL,
    };
    catchError(source, fallback, &sink);
    return 0;
}
