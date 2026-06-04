#include <stdio.h>

int sum(const int *xs, int n) {
    if (n == 0) return 0;
    return xs[0] + sum(xs + 1, n - 1);
}

int main(void) {
    int xs[] = { 1, 2, 3, 4 };
    printf("%d\n", sum(xs, 4));
    return 0;
}
