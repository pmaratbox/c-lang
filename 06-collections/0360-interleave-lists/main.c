#include <stdio.h>

int main(void) {
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    int n = 3;

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d %d", a[i], b[i]);
    }
    printf("\n");
    return 0;
}
