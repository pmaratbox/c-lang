#include <stdio.h>

static int gcd(int a, int b) {
    while (b) { int t = a % b; a = b; b = t; }
    return a < 0 ? -a : a;
}

int main(void) {
    int n1 = 1, d1 = 2, n2 = 1, d2 = 3;
    int num = n1 * d2 + n2 * d1;
    int den = d1 * d2;
    int g = gcd(num, den);
    printf("%d/%d\n", num / g, den / g);
    return 0;
}
