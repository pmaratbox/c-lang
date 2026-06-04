#include <stdio.h>

int main(void) {
    int coins[] = {1, 2, 5};
    int n = 3, target = 5;
    int dp[6] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int a = coins[i]; a <= target; a++) {
            dp[a] += dp[a - coins[i]];
        }
    }
    printf("%d\n", dp[target]);
    return 0;
}
