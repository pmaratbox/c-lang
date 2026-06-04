#include <stdio.h>

static int ext_gcd(int a, int b, int *x, int *y) {
    if (b == 0) { *x = 1; *y = 0; return a; }
    int x1, y1;
    int g = ext_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

int main(void) {
    int x, y;
    int g = ext_gcd(30, 12, &x, &y);
    printf("%d %d %d\n", g, x, y);
    return 0;
}
