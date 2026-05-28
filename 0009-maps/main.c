#include <stdio.h>
#include <string.h>

struct entry {
    const char *key;
    int value;
};

int main(void) {
    struct entry nums[] = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
    };
    size_t size = sizeof(nums) / sizeof(nums[0]);

    for (size_t i = 0; i < size; i++) {
        if (strcmp(nums[i].key, "two") == 0) {
            printf("two: %d\n", nums[i].value);
            break;
        }
    }
    printf("size: %zu\n", size);
    return 0;
}
