#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7, size = 3;
    for (int i = 0; i < n; i += size) {
        for (int j = i; j < i + size && j < n; j++) {
            if (j > i) printf(" ");
            printf("%d", nums[j]);
        }
        printf("\n");
    }
    return 0;
}
