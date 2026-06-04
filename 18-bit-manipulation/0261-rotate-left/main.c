#include <stdio.h>

static unsigned char rol8(unsigned char x, int n) {
    return (unsigned char)(((x << n) | (x >> (8 - n))) & 0xff);
}

int main(void) {
    printf("%u %u\n", rol8(1, 1), rol8(128, 1));
    return 0;
}
