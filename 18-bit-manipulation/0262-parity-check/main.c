#include <stdio.h>

static int parity(unsigned x) {
    int p = 0;
    while (x) {
        p ^= 1;
        x &= x - 1;
    }
    return p;
}

int main(void) {
    printf("%d %d\n", parity(7), parity(5));
    return 0;
}
