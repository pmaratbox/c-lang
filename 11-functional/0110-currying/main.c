#include <stdio.h>

/* C has no closures, so currying is emulated: add returns an Adder
   struct capturing the first argument, applied later by apply. */
typedef struct {
    int first;
} Adder;

Adder add(int a) {
    Adder adder = {a};
    return adder;
}

int apply(Adder adder, int b) {
    return adder.first + b;
}

int main(void) {
    printf("%d\n", apply(add(2), 3));
    return 0;
}
