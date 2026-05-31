#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(nums) / sizeof(nums[0]);

    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) {
            sum += nums[i] * 2;
        }
    }

    printf("sum: %d\n", sum);
    return 0;
}
