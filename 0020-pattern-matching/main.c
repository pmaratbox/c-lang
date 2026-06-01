#include <stdio.h>

const char *word(int n) {
    switch (n) {
        case 1: return "one";
        case 2: return "two";
        default: return "many";
    }
}

int main(void) {
    int nums[] = {1, 2, 5};
    for (size_t i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        printf("%d: %s\n", nums[i], word(nums[i]));
    }
    return 0;
}
