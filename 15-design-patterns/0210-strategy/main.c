#include <stdio.h>

typedef int (*Strategy)(int, int);

static int add(int a, int b) { return a + b; }
static int mul(int a, int b) { return a * b; }

int main(void) {
    Strategy s = add;
    int r1 = s(3, 4);
    s = mul;
    int r2 = s(3, 4);
    printf("%d %d\n", r1, r2);
    return 0;
}
