#include <stdio.h>

typedef int (*Fn)(int);

int inc(int x) { return x + 1; }
int twice(int x) { return x * 2; }

int compose(Fn f, Fn g, int x) {
    return f(g(x));
}

int main(void) {
    printf("%d\n", compose(inc, twice, 3));
    return 0;
}
