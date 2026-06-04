#include <stdio.h>

static unsigned ackermann(unsigned m, unsigned n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return ackermann(m - 1, 1);
    }
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main(void) {
    printf("%u\n", ackermann(2, 3));
    return 0;
}
