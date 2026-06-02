#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j > i) break; /* skip rest of this row -> next i */
            if (i * j == 4) {
                printf("stop at %d,%d\n", i, j);
                goto done; /* break out of both loops */
            }
            printf("%d,%d\n", i, j);
        }
    }
done:
    return 0;
}
