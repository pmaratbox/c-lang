#include <stdio.h>
#include <string.h>

int main(void) {
    const char *text = "ababab";
    const char *pat = "ab";
    int m = (int)strlen(pat);
    int n = (int)strlen(text);

    int lps[64] = {0};
    for (int i = 1, len = 0; i < m;) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    int first = 1;
    for (int i = 0, j = 0; i < n;) {
        if (text[i] == pat[j]) {
            i++; j++;
            if (j == m) {
                if (!first) printf(" ");
                printf("%d", i - j);
                first = 0;
                j = lps[j - 1];
            }
        } else if (j) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    printf("\n");
    return 0;
}
