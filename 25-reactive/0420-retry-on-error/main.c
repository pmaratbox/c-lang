#include <stdio.h>

/* A minimal push-based Observable implemented from scratch.
 * An observer is a struct of next/error/complete callbacks. subscribe wires a
 * producer to it. retry(n) resubscribes to the source on error up to n times. */

typedef struct Observer {
    void (*next)(struct Observer *self, int value);
    void (*error)(struct Observer *self);
    void (*complete)(struct Observer *self);
    void *state;
} Observer;

/* The source: on each subscription it increments a shared attempt counter,
 * prints "attempt <k>", errors for k<3, and emits+completes for k==3. */
static int attempt_count = 0;

static void source_subscribe(Observer *obs) {
    int k = ++attempt_count;
    printf("attempt %d\n", k);
    if (k < 3) {
        obs->error(obs);
    } else {
        obs->next(obs, 42);
        obs->complete(obs);
    }
}

/* retry operator: an observer wrapper that, on error, resubscribes to the
 * source while resubscriptions remain. */
typedef struct {
    Observer base;
    Observer *downstream;
    int remaining;
} RetryObserver;

static void retry_next(Observer *self, int value) {
    RetryObserver *r = (RetryObserver *)self->state;
    r->downstream->next(r->downstream, value);
}

static void retry_complete(Observer *self) {
    RetryObserver *r = (RetryObserver *)self->state;
    r->downstream->complete(r->downstream);
}

static void retry_error(Observer *self) {
    RetryObserver *r = (RetryObserver *)self->state;
    if (r->remaining > 0) {
        r->remaining--;
        source_subscribe(&r->base);
    } else {
        r->downstream->error(r->downstream);
    }
}

static void retry_subscribe(int n, Observer *downstream) {
    RetryObserver r;
    r.base.next = retry_next;
    r.base.error = retry_error;
    r.base.complete = retry_complete;
    r.base.state = &r;
    r.downstream = downstream;
    r.remaining = n;
    source_subscribe(&r.base);
}

/* Final observer: prints "ok" on success. */
static void final_next(Observer *self, int value) {
    (void)self;
    (void)value;
    printf("ok\n");
}

static void final_error(Observer *self) {
    (void)self;
}

static void final_complete(Observer *self) {
    (void)self;
}

int main(void) {
    Observer sink;
    sink.next = final_next;
    sink.error = final_error;
    sink.complete = final_complete;
    sink.state = 0;

    retry_subscribe(2, &sink);
    return 0;
}
