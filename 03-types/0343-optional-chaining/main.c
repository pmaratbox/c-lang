#include <stdio.h>
#include <stdbool.h>

typedef struct { int value; bool present; } OptC;
typedef struct { OptC c; bool present; } OptB;
typedef struct { OptB b; bool present; } A;

static int read_c(A a, int fallback) {
    if (a.present && a.b.present && a.b.c.present) {
        return a.b.c.value;
    }
    return fallback;
}

int main(void) {
    A full = { .present = true, .b = { .present = true, .c = { .value = 5, .present = true } } };
    A empty = { .present = true, .b = { .present = false } };
    printf("%d %d\n", read_c(full, 0), read_c(empty, 0));
    return 0;
}
