#include <stdio.h>

int main(void) {
    int nums[] = {1, 5, 11, 5};
    int n = 4;
    int total = 0;
    for (int i = 0; i < n; i++) total += nums[i];
    if (total % 2 != 0) {
        printf("no\n");
        return 0;
    }
    int target = total / 2;
    int dp[12] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int s = target; s >= nums[i]; s--) {
            if (dp[s - nums[i]]) dp[s] = 1;
        }
    }
    printf("%s\n", dp[target] ? "yes" : "no");
    return 0;
}
