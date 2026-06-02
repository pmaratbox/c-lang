#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4, 5};
    size_t count = sizeof(nums) / sizeof(nums[0]);

    printf("count: %zu\n", count);
    printf("first: %d\n", nums[0]);
    printf("last: %d\n", nums[count - 1]);
    return 0;
}
