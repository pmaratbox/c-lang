#include <stdio.h>

int main(void) {
    int a[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;
    int dp[8];
    int best = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > best) best = dp[i];
    }
    printf("%d\n", best);
    return 0;
}
