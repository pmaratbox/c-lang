#include <stdio.h>

int main(void) {
    long base = 3, exp = 13, mod = 7;
    long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    printf("%ld\n", result);
    return 0;
}
