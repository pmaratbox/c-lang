#include <stdio.h>

/* zipWith applies a binary function pointer to paired elements of two
   arrays, writing the results into an output array. */
typedef int (*BinOp)(int, int);

int add(int a, int b) { return a + b; }

void zip_with(BinOp op, const int *xs, const int *ys, int *out, int n) {
    for (int i = 0; i < n; i++) {
        out[i] = op(xs[i], ys[i]);
    }
}

int main(void) {
    int xs[] = {1, 2, 3};
    int ys[] = {4, 5, 6};
    int out[3];
    zip_with(add, xs, ys, out, 3);
    for (int i = 0; i < 3; i++) {
        printf("%d%s", out[i], i < 2 ? " " : "\n");
    }
    return 0;
}
