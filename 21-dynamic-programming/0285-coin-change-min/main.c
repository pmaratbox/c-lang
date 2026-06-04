#include <stdio.h>

int main(void) {
    int coins[] = {1, 2, 5};
    int n = 3, target = 11;
    int dp[12];
    dp[0] = 0;
    for (int a = 1; a <= target; a++) {
        dp[a] = target + 1;
        for (int i = 0; i < n; i++) {
            if (coins[i] <= a && dp[a - coins[i]] + 1 < dp[a]) {
                dp[a] = dp[a - coins[i]] + 1;
            }
        }
    }
    printf("%d\n", dp[target]);
    return 0;
}
