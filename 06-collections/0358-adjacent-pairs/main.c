#include <stdio.h>

int main(void) {
    int a[] = {1, 2, 3, 4};
    int n = 4;

    for (int i = 0; i + 1 < n; i++) {
        if (i > 0) printf(" ");
        printf("%d,%d", a[i], a[i + 1]);
    }
    printf("\n");
    return 0;
}
