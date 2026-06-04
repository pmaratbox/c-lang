#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        printf("%s", nums[i] % 2 == 0 ? "even" : "odd");
        printf(i < 3 ? " " : "\n");
    }
    return 0;
}
