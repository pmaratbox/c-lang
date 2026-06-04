#include <stdio.h>

static int popcount(unsigned x) {
    int c = 0;
    while (x) {
        x &= x - 1;
        c++;
    }
    return c;
}

int main(void) {
    printf("%d\n", popcount(1u ^ 4u));
    return 0;
}
