#include <stdio.h>

int main(void) {
    int rows = 3, cols = 3;
    int dp[3];
    for (int j = 0; j < cols; j++) dp[j] = 1;
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[j] += dp[j - 1];
        }
    }
    printf("%d\n", dp[cols - 1]);
    return 0;
}
