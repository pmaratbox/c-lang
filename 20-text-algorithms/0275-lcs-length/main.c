#include <stdio.h>
#include <string.h>

int main(void) {
    const char *a = "ABCBDAB";
    const char *b = "BDCAB";
    int n = (int)strlen(a);
    int m = (int)strlen(b);

    int dp[64][64] = {{0}};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1]
                               ? dp[i - 1][j]
                               : dp[i][j - 1];
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
