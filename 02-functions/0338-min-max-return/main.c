#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax min_max(const int *xs, int n) {
    MinMax r = { xs[0], xs[0] };
    for (int i = 1; i < n; i++) {
        if (xs[i] < r.min) r.min = xs[i];
        if (xs[i] > r.max) r.max = xs[i];
    }
    return r;
}

int main(void) {
    int xs[] = { 4, 1, 7 };
    MinMax r = min_max(xs, 3);
    printf("%d %d\n", r.min, r.max);
    return 0;
}
