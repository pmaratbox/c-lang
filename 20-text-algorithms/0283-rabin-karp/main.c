#include <stdio.h>
#include <string.h>

int main(void) {
    const char *text = "xabxab";
    const char *pat = "ab";
    int n = (int)strlen(text);
    int m = (int)strlen(pat);

    const unsigned long base = 256, mod = 1000000007UL;
    unsigned long ph = 0, th = 0, pow = 1;
    for (int i = 0; i < m; i++) {
        ph = (ph * base + (unsigned char)pat[i]) % mod;
        th = (th * base + (unsigned char)text[i]) % mod;
        if (i) pow = (pow * base) % mod;
    }

    int first = 1;
    for (int i = 0; i + m <= n; i++) {
        if (i > 0) {
            th = (th + mod - ((unsigned char)text[i - 1] * pow) % mod) % mod;
            th = (th * base + (unsigned char)text[i + m - 1]) % mod;
        }
        if (th == ph && strncmp(text + i, pat, m) == 0) {
            if (!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
