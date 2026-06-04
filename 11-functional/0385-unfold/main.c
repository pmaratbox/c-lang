#include <stdio.h>

int main(void) {
    int x = 1;
    for (int i = 0; i < 5; i++) {
        if (i > 0) printf(" ");
        printf("%d", x);
        x = x * 2;
    }
    printf("\n");
    return 0;
}
