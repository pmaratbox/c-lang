#include <stdio.h>

int main(void) {
    int nums[] = {1, 2};
    char letters[] = {'a', 'b'};
    int nn = sizeof(nums) / sizeof(nums[0]);
    int ln = sizeof(letters) / sizeof(letters[0]);

    int first = 1;
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < ln; j++) {
            printf(first ? "%d%c" : " %d%c", nums[i], letters[j]);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
