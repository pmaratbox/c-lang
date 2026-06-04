#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s = "aaaa";
    int n = (int)strlen(s);

    int z[64] = {0};
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r) {
            int k = r - i < z[i - l] ? r - i : z[i - l];
            z[i] = k;
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }

    for (int i = 1; i < n; i++) {
        if (i > 1) printf(" ");
        printf("%d", z[i]);
    }
    printf("\n");
    return 0;
}
