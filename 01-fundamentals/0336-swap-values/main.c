#include <stdio.h>

int main(void) {
    int a = 1, b = 2;
    int tmp = a;
    a = b;
    b = tmp;
    printf("%d %d\n", a, b);
    return 0;
}
