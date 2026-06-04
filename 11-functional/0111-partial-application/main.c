#include <stdio.h>

/* Partial application is emulated with a struct that binds the first
   argument; apply supplies the remaining one. */
typedef struct {
    int bound;
} PartialAdd;

PartialAdd bind_add(int a) {
    PartialAdd p = {a};
    return p;
}

int apply(PartialAdd p, int b) {
    return p.bound + b;
}

int main(void) {
    PartialAdd add10 = bind_add(10);
    printf("%d\n", apply(add10, 3));
    return 0;
}
