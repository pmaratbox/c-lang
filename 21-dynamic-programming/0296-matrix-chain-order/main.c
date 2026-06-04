#include <stdio.h>
#include <limits.h>

int main(void) {
    int p[] = {10, 20, 30, 40};
    int n = 4; /* 3 matrices */
    int dp[4][4] = {{0}};
    for (int len = 2; len < n; len++) {
        for (int i = 1; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }
    printf("%d\n", dp[1][n - 1]);
    return 0;
}
