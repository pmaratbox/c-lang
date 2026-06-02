#include <stdio.h>

int main(void) {
    const char *letters[] = {"a", "b", "c"};
    int nums[] = {1, 2, 3};
    size_t n = 3;
    for (size_t i = 0; i < n; i++) {
        printf("%s=%d", letters[i], nums[i]);
        if (i + 1 < n) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
