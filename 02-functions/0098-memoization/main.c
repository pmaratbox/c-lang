#include <stdio.h>

static int cache[11];
static int computed[11];

static int fib(int n) {
    if (n < 2) return n;
    if (computed[n]) return cache[n];
    cache[n] = fib(n - 1) + fib(n - 2);
    computed[n] = 1;
    return cache[n];
}

int main(void) {
    printf("%d\n", fib(10));
    return 0;
}
