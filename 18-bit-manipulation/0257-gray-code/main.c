#include <stdio.h>

int main(void) {
    for (int n = 0; n < 4; n++) {
        printf("%d", n ^ (n >> 1));
        if (n < 3) printf(" ");
    }
    printf("\n");
    return 0;
}
