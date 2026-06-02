#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4};
    int n = 4, size = 2;
    for (int i = 0; i + size <= n; i++) {
        for (int j = i; j < i + size; j++) {
            if (j > i) printf(" ");
            printf("%d", nums[j]);
        }
        printf("\n");
    }
    return 0;
}
