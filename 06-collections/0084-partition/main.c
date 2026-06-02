#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    printf("evens:");
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) printf(" %d", nums[i]);
    }
    printf("\n");
    printf("odds:");
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 != 0) printf(" %d", nums[i]);
    }
    printf("\n");
    return 0;
}
