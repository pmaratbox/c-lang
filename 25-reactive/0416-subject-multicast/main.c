#include <stdio.h>

/* A push-based Observer: a next callback plus a tag for its label. */
typedef struct {
    int tag;
} Observer;

static void observer_next(const Observer *o, int v) {
    printf("obs%d: %d\n", o->tag, v);
}

/* A Subject keeps a list of observers; subscribe appends; next iterates. */
typedef struct {
    Observer observers[8];
    int count;
} Subject;

static void subject_subscribe(Subject *s, int tag) {
    s->observers[s->count].tag = tag;
    s->count++;
}

static void subject_next(Subject *s, int v) {
    for (int i = 0; i < s->count; i++) {
        observer_next(&s->observers[i], v);
    }
}

int main(void) {
    Subject subject = { .count = 0 };

    subject_subscribe(&subject, 1); /* obs1 */
    subject_subscribe(&subject, 2); /* obs2 */

    subject_next(&subject, 1);
    subject_next(&subject, 2);

    return 0;
}
