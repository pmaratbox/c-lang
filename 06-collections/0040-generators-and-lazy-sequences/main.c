#include <stdio.h>

int next_square(void) {
    static int n = 0;
    n++;
    return n * n;
}

int main(void) {
    int a = next_square();
    int b = next_square();
    int c = next_square();
    printf("%d %d %d\n", a, b, c);
    return 0;
}
