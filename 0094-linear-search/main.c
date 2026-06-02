#include <stdio.h>

int main(void) {
    int nums[] = {4, 2, 7, 1, 9};
    int n = 5, target = 7;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            index = i;
            break;
        }
    }
    printf("found %d at index %d\n", target, index);
    return 0;
}
