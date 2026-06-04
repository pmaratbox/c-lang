#include <stdio.h>

int main(void) {
    int grid[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int n = 3;
    int dp[3];
    dp[0] = grid[0][0];
    for (int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];
    for (int i = 1; i < n; i++) {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; j++) {
            int up = dp[j];
            int left = dp[j - 1];
            dp[j] = (up < left ? up : left) + grid[i][j];
        }
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}
