#include <stdio.h>

static int clamp(int x, int lo, int hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

int main(void) {
    printf("%d %d\n", clamp(15, 0, 10), clamp(-3, 0, 10));
    return 0;
}
