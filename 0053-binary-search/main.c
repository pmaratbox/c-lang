#include <stdio.h>

int main(void) {
    int nums[] = {1, 3, 5, 7, 9};
    int target = 7;
    int n = (int)(sizeof(nums) / sizeof(nums[0]));

    int lo = 0, hi = n - 1, index = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] == target) {
            index = mid;
            break;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("found %d at index %d\n", target, index);
    return 0;
}
