#include <stdio.h>

/* A push-based Observable implemented from scratch.
   ReplaySubject keeps a buffer of the last N emitted values; a late
   subscriber first receives the buffered values, then any new ones. */

#define BUFCAP 2

typedef struct {
    void (*next)(void *ctx, int value);
} Observer;

typedef struct {
    int buf[BUFCAP];
    int len;            /* number of valid entries in buf */
    Observer *observer; /* single late subscriber (or NULL) */
    void *observer_ctx;
} ReplaySubject;

static void subject_init(ReplaySubject *s) {
    s->len = 0;
    s->observer = NULL;
    s->observer_ctx = NULL;
}

static void subject_next(ReplaySubject *s, int value) {
    /* push into the ring of the last BUFCAP values */
    if (s->len < BUFCAP) {
        s->buf[s->len++] = value;
    } else {
        for (int i = 1; i < BUFCAP; i++) s->buf[i - 1] = s->buf[i];
        s->buf[BUFCAP - 1] = value;
    }
    /* forward live to a current subscriber */
    if (s->observer) s->observer->next(s->observer_ctx, value);
}

static void subject_subscribe(ReplaySubject *s, Observer *o, void *ctx) {
    s->observer = o;
    s->observer_ctx = ctx;
    /* replay the buffer to the late subscriber */
    for (int i = 0; i < s->len; i++) o->next(ctx, s->buf[i]);
}

static void print_next(void *ctx, int value) {
    (void)ctx;
    printf("%d\n", value);
}

int main(void) {
    ReplaySubject subject;
    subject_init(&subject);

    subject_next(&subject, 1);
    subject_next(&subject, 2);
    subject_next(&subject, 3); /* buffer now [2, 3] */

    Observer late = { print_next };
    subject_subscribe(&subject, &late, NULL); /* replays 2, 3 */

    subject_next(&subject, 4); /* subscriber receives 4 */

    return 0;
}
