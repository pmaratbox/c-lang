#include <stdio.h>

/* An observer is a callback plus a name; subscribe registers it and
   immediately replays the subject's current value. */

typedef void (*next_fn)(const char *name, int v);

#define MAX_OBS 8

typedef struct {
    const char *name;
    next_fn next;
} Observer;

typedef struct {
    int current;
    Observer obs[MAX_OBS];
    int count;
} BehaviorSubject;

static void print_next(const char *name, int v) {
    printf("%s: %d\n", name, v);
}

static void subject_subscribe(BehaviorSubject *s, const char *name, next_fn next) {
    if (s->count < MAX_OBS) {
        s->obs[s->count].name = name;
        s->obs[s->count].next = next;
        s->count++;
    }
    /* replay current value to the new subscriber */
    next(name, s->current);
}

static void subject_next(BehaviorSubject *s, int v) {
    s->current = v;
    for (int i = 0; i < s->count; i++) {
        s->obs[i].next(s->obs[i].name, v);
    }
}

int main(void) {
    BehaviorSubject s = { .current = 0, .count = 0 };

    subject_subscribe(&s, "A", print_next);
    subject_next(&s, 1);
    subject_subscribe(&s, "B", print_next);
    subject_next(&s, 2);

    return 0;
}
