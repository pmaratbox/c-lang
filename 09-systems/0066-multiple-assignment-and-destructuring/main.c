#include <stdio.h>

int main(void) {
    int a = 1, b = 2;
    int tmp = a;
    a = b;
    b = tmp;
    printf("%d %d\n", a, b);

    int pair[2] = {3, 4};
    int x = pair[0], y = pair[1];
    printf("%d %d\n", x, y);
    return 0;
}
