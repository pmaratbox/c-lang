#include <stdio.h>

int main(void) {
    int nums[] = {10, 20, 30, 40, 50};
    printf("slice:");
    for (int i = 1; i < 4; i++) {
        printf(" %d", nums[i]);
    }
    printf("\n");
    return 0;
}
