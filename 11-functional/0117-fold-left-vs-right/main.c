#include <stdio.h>

/* foldl accumulates from the left (acc op x); foldr recurses from the
   right (x op acc). Both use a binary function pointer. */
typedef int (*BinOp)(int, int);

int sub(int a, int b) { return a - b; }

int foldl(BinOp op, int acc, const int *xs, int n) {
    for (int i = 0; i < n; i++) {
        acc = op(acc, xs[i]);
    }
    return acc;
}

int foldr(BinOp op, const int *xs, int n, int acc) {
    for (int i = n - 1; i >= 0; i--) {
        acc = op(xs[i], acc);
    }
    return acc;
}

int main(void) {
    int xs[] = {1, 2, 3};
    int left = foldl(sub, 0, xs, 3);
    int right = foldr(sub, xs, 3, 0);
    printf("%d %d\n", left, right);
    return 0;
}
