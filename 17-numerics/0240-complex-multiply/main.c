#include <stdio.h>

int main(void) {
    int ar = 1, ai = 2, br = 3, bi = 4;
    int re = ar * br - ai * bi;
    int im = ar * bi + ai * br;
    printf("%d %d\n", re, im);
    return 0;
}
