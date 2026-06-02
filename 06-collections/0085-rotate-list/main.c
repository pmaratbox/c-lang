#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", nums[(i + k) % n]);
    }
    printf("\n");
    return 0;
}
