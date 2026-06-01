#include <stdio.h>

int main(void) {
    int nums[] = {4, 7};
    for (size_t i = 0; i < 2; i++) {
        const char *label = nums[i] % 2 == 0 ? "even" : "odd";
        printf("%d: %s\n", nums[i], label);
    }
    return 0;
}
