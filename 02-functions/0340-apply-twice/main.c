#include <stdio.h>

int apply_twice(int (*f)(int), int x) {
    return f(f(x));
}

int inc(int x) {
    return x + 1;
}

int main(void) {
    printf("%d\n", apply_twice(inc, 3));
    return 0;
}
