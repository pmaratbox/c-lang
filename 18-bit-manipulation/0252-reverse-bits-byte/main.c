#include <stdio.h>

static unsigned char reverse8(unsigned char x) {
    unsigned char r = 0;
    for (int i = 0; i < 8; i++) {
        r = (unsigned char)((r << 1) | (x & 1));
        x >>= 1;
    }
    return r;
}

int main(void) {
    printf("%u\n", reverse8(1));
    return 0;
}
