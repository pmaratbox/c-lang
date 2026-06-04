#include <stdio.h>

typedef struct Colleague {
    const char *name;
    struct Mediator *mediator;
} Colleague;

typedef struct Mediator {
    Colleague *a;
    Colleague *b;
} Mediator;

void receive(Colleague *c, const char *msg) {
    printf("%s got: %s\n", c->name, msg);
}

void send(Mediator *m, Colleague *from, const char *msg) {
    Colleague *to = (from == m->a) ? m->b : m->a;
    receive(to, msg);
}

int main(void) {
    Mediator m;
    Colleague a = {"A", &m};
    Colleague b = {"B", &m};
    m.a = &a;
    m.b = &b;
    send(&m, &a, "hi");
    return 0;
}
