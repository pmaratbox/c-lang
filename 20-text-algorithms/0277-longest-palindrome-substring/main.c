#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s = "babad";
    int n = (int)strlen(s);
    int bestStart = 0, bestLen = 1;

    for (int c = 0; c < n; c++) {
        for (int d = 0; d < 2; d++) {
            int lo = c, hi = c + d;
            while (lo >= 0 && hi < n && s[lo] == s[hi]) {
                int len = hi - lo + 1;
                if (len > bestLen) {
                    bestLen = len;
                    bestStart = lo;
                }
                lo--; hi++;
            }
        }
    }
    for (int i = bestStart; i < bestStart + bestLen; i++) {
        putchar(s[i]);
    }
    printf("\n");
    return 0;
}
