#include <stdio.h>

int main(void) {
    int value = 258;
    unsigned char hi = (unsigned char)((value >> 8) & 0xFF);
    unsigned char lo = (unsigned char)(value & 0xFF);
    int decoded = hi * 256 + lo;
    printf("%d %d %d\n", hi, lo, decoded);
    return 0;
}
