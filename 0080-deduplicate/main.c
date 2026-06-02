#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 2, 3, 1};
    int n = 5;
    int unique[5];
    int count = 0;
    for (int i = 0; i < n; i++) {
        int dup = 0;
        for (int j = 0; j < count; j++) {
            if (unique[j] == nums[i]) {
                dup = 1;
                break;
            }
        }
        if (!dup) unique[count++] = nums[i];
    }
    for (int i = 0; i < count; i++) {
        if (i > 0) printf(" ");
        printf("%d", unique[i]);
    }
    printf("\n");
    return 0;
}
