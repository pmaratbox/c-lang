#include <stdio.h>

int inc(int x) {
    return x + 1;
}

int dbl(int x) {
    return x * 2;
}

int apply(int (*f)(int), int x) {
    return f(x);
}

int main(void) {
    printf("inc 5 = %d\n", apply(inc, 5));
    printf("double 5 = %d\n", apply(dbl, 5));
    return 0;
}
