#include <stdio.h>

void greet(const char *name, const char *greeting) {
    printf("%s, %s\n", greeting, name);
}

void greet_default(const char *name) {
    greet(name, "Hello");
}

int main(void) {
    greet_default("Ada");
    greet("Ada", "Hi");
    return 0;
}
