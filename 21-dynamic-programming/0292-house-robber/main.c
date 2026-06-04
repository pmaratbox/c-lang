#include <stdio.h>

int main(void) {
    int nums[] = {2, 7, 9, 3, 1};
    int n = 5;
    int prev = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        int take = prev + nums[i];
        int best = take > curr ? take : curr;
        prev = curr;
        curr = best;
    }
    printf("%d\n", curr);
    return 0;
}
