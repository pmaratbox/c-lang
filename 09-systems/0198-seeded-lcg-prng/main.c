#include <stdio.h>

int main(void) {
    int x = 1; /* seed */
    for (int i = 0; i < 3; i++) {
        x = (5 * x + 3) % 16;
        printf("%d", x);
        if (i < 2) printf(" ");
    }
    printf("\n");
    return 0;
}
