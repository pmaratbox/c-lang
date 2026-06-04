#include <stdio.h>

static int ctz(unsigned x) {
    int c = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        c++;
    }
    return c;
}

int main(void) {
    printf("%d\n", ctz(8));
    return 0;
}
