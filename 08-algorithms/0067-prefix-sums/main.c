#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4};
    int n = (int)(sizeof(nums) / sizeof(nums[0]));

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += nums[i];
        if (i > 0) printf(" ");
        printf("%d", total);
    }
    printf("\n");
    return 0;
}
