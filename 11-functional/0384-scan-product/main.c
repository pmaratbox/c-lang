#include <stdio.h>

int main(void) {
    int a[] = {1, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);

    long acc = 1;
    for (int i = 0; i < n; i++) {
        acc *= a[i];
        if (i > 0) printf(" ");
        printf("%ld", acc);
    }
    printf("\n");
    return 0;
}
