#include <stdio.h>

/* Point-free: compose without naming the argument. sumOfSquares is the
   composition of map(square) and sum, expressed as a fused fold. */
static int square(int x) { return x * x; }

static int sum_map(int (*f)(int), const int *xs, int n) {
    int acc = 0;
    for (int i = 0; i < n; i++) acc += f(xs[i]);
    return acc;
}

/* sumOfSquares = sum . map square */
static int sum_of_squares(const int *xs, int n) {
    return sum_map(square, xs, n);
}

int main(void) {
    int xs[] = {1, 2, 3};
    printf("%d\n", sum_of_squares(xs, 3));
    return 0;
}
