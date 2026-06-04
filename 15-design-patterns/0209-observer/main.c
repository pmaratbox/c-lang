#include <stdio.h>

typedef struct {
    const char *id;
} Observer;

typedef struct {
    Observer *observers[8];
    int count;
} Subject;

void subscribe(Subject *s, Observer *o) {
    s->observers[s->count++] = o;
}

void notify(Subject *s, int value) {
    for (int i = 0; i < s->count; i++) {
        printf("%s: %d\n", s->observers[i]->id, value);
    }
}

int main(void) {
    Observer obs1 = {"obs1"};
    Observer obs2 = {"obs2"};
    Subject s = {{0}, 0};
    subscribe(&s, &obs1);
    subscribe(&s, &obs2);
    notify(&s, 5);
    return 0;
}
