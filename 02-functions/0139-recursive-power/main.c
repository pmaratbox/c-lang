#include <stdio.h>

static long power(long base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp - 1);
}

int main(void) {
    printf("%ld\n", power(2, 10));
    return 0;
}
