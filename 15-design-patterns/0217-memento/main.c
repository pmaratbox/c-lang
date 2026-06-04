#include <stdio.h>

typedef struct {
    int state;
} Memento;

typedef struct {
    int state;
} Originator;

Memento save(const Originator *o) {
    Memento m = {o->state};
    return m;
}

void restore(Originator *o, const Memento *m) {
    o->state = m->state;
}

int main(void) {
    Originator o = {1};
    Memento m = save(&o);
    o.state = 2;
    printf("%d ", o.state);
    restore(&o, &m);
    printf("%d\n", o.state);
    return 0;
}
