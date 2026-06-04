#include <stdio.h>

static int gcd(int a, int b) {
    while (b) { int t = a % b; a = b; b = t; }
    return a < 0 ? -a : a;
}

int main(void) {
    int num = 6, den = 8;
    int g = gcd(num, den);
    printf("%d/%d\n", num / g, den / g);
    return 0;
}
