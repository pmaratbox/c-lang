#include <stdio.h>

int main(void) {
    long base = 2, exp = 10, result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    printf("%ld\n", result);
    return 0;
}
