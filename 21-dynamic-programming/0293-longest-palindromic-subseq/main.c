#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s = "bbbab";
    int n = (int)strlen(s);
    int dp[8][8] = {{0}};
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                int a = dp[i + 1][j];
                int b = dp[i][j - 1];
                dp[i][j] = a > b ? a : b;
            }
        }
    }
    printf("%d\n", dp[0][n - 1]);
    return 0;
}
