#include <stdio.h>

void reverse_print(const int *xs, int n) {
    if (n == 0) return;
    printf("%d", xs[n - 1]);
    if (n > 1) printf(" ");
    reverse_print(xs, n - 1);
}

int main(void) {
    int xs[] = { 1, 2, 3 };
    reverse_print(xs, 3);
    printf("\n");
    return 0;
}
