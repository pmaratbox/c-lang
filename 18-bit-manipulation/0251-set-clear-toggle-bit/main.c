#include <stdio.h>

int main(void) {
    int s = 0 | (1 << 1);
    int c = 2 & ~(1 << 1);
    int t = 0 ^ (1 << 1);
    printf("%d %d %d\n", s, c, t);
    return 0;
}
