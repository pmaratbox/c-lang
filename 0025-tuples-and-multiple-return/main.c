#include <stdio.h>

void min_max(int a, int b, int *lo, int *hi) {
    if (a < b) {
        *lo = a;
        *hi = b;
    } else {
        *lo = b;
        *hi = a;
    }
}

int main(void) {
    int lo, hi;
    min_max(3, 7, &lo, &hi);
    printf("min: %d\n", lo);
    printf("max: %d\n", hi);
    return 0;
}
