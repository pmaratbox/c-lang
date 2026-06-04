#include <stdio.h>

int main(void) {
    long c = 1;
    for (int n = 0; n < 5; n++) {
        if (n > 0) putchar(' ');
        printf("%ld", c);
        c = c * 2 * (2 * n + 1) / (n + 2);
    }
    putchar('\n');
    return 0;
}
