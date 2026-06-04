#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(void) {
    int a = 4, b = 6;
    int lcm = a / gcd(a, b) * b;
    printf("%d\n", lcm);
    return 0;
}
