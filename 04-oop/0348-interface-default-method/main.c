#include <stdio.h>

typedef struct Greeter {
    const char *(*greet)(const struct Greeter *self);
} Greeter;

/* default implementation */
static const char *default_greet(const Greeter *self) {
    (void)self;
    return "hi";
}

/* overriding implementation */
static const char *override_greet(const Greeter *self) {
    (void)self;
    return "hey";
}

int main(void) {
    Greeter base = { default_greet };
    Greeter impl = { override_greet };
    printf("%s %s\n", base.greet(&base), impl.greet(&impl));
    return 0;
}
