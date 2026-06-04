#include <stdio.h>
#include <string.h>

static int min3(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int main(void) {
    const char *a = "kitten";
    const char *b = "sitting";
    int n = (int)strlen(a);
    int m = (int)strlen(b);

    int dp[64][64];
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            dp[i][j] = min3(dp[i - 1][j] + 1,
                            dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + cost);
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
