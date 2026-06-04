#include <stdio.h>

int main(void) {
    int w[] = {2, 3, 4};
    int v[] = {3, 4, 5};
    int n = 3, cap = 5;
    int dp[6] = {0};
    for (int i = 0; i < n; i++) {
        for (int c = cap; c >= w[i]; c--) {
            int cand = dp[c - w[i]] + v[i];
            if (cand > dp[c]) dp[c] = cand;
        }
    }
    printf("%d\n", dp[cap]);
    return 0;
}
