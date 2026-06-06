#include <stdio.h>

/* Fine-grained reactivity: a writable signal holds a value plus a list of
 * subscriber callbacks; a computed registers a recompute callback as a
 * subscriber of the signals it reads and caches its result. */

typedef void (*Subscriber)(void);

#define MAX_SUBS 8

typedef struct {
    int value;
    Subscriber subs[MAX_SUBS];
    int sub_count;
} Signal;

static void signal_init(Signal *s, int value) {
    s->value = value;
    s->sub_count = 0;
}

static int signal_get(Signal *s) {
    return s->value;
}

static void signal_subscribe(Signal *s, Subscriber cb) {
    if (s->sub_count < MAX_SUBS) {
        s->subs[s->sub_count++] = cb;
    }
}

static void signal_set(Signal *s, int value) {
    s->value = value;
    for (int i = 0; i < s->sub_count; i++) {
        s->subs[i]();
    }
}

/* signals a=2, b=3; computed sum = a()+b() */
static Signal a, b;
static int sum_cache;

static void sum_recompute(void) {
    sum_cache = signal_get(&a) + signal_get(&b);
}

int main(void) {
    signal_init(&a, 2);
    signal_init(&b, 3);

    /* computed registers recompute as a subscriber of its dependencies */
    signal_subscribe(&a, sum_recompute);
    signal_subscribe(&b, sum_recompute);
    sum_recompute();

    printf("%d\n", sum_cache);

    signal_set(&a, 10);
    printf("%d\n", sum_cache);

    return 0;
}
