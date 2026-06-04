#include <stdio.h>

int main(void) {
    int nums[] = {3, 34, 4, 12, 5, 2};
    int n = 6, target = 9;
    int dp[10] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int s = target; s >= nums[i]; s--) {
            if (dp[s - nums[i]]) dp[s] = 1;
        }
    }
    printf("%s\n", dp[target] ? "yes" : "no");
    return 0;
}
