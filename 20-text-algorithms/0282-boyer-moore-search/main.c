#include <stdio.h>
#include <string.h>

int main(void) {
    const char *text = "zzabc";
    const char *pat = "abc";
    int n = (int)strlen(text);
    int m = (int)strlen(pat);

    int last[256];
    for (int i = 0; i < 256; i++) last[i] = -1;
    for (int i = 0; i < m; i++) last[(unsigned char)pat[i]] = i;

    int found = -1;
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pat[j] == text[s + j]) j--;
        if (j < 0) {
            found = s;
            break;
        }
        int bc = last[(unsigned char)text[s + j]];
        int shift = j - bc;
        s += shift > 1 ? shift : 1;
    }
    printf("%d\n", found);
    return 0;
}
