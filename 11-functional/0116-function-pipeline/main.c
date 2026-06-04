#include <stdio.h>

/* A pipeline applies an array of unary function pointers left to right,
   threading the value through each stage. */
typedef int (*Fn)(int);

int inc(int x) { return x + 1; }
int doubler(int x) { return x * 2; }
int negate(int x) { return -x; }

int pipe(const Fn *stages, int n, int x) {
    for (int i = 0; i < n; i++) {
        x = stages[i](x);
    }
    return x;
}

int main(void) {
    Fn stages[] = {inc, doubler, negate};
    printf("%d\n", pipe(stages, 3, 3));
    return 0;
}
