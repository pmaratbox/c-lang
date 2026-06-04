#include <stdio.h>

int main(void) {
    unsigned r = 1, g = 2, b = 3;
    unsigned packed = (r << 16) | (g << 8) | b;
    unsigned ur = (packed >> 16) & 0xff;
    unsigned ug = (packed >> 8) & 0xff;
    unsigned ub = packed & 0xff;
    printf("%u %u %u\n", ur, ug, ub);
    return 0;
}
