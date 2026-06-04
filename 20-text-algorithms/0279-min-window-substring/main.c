#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s = "ADOBECODEBANC";
    const char *t = "ABC";
    int n = (int)strlen(s);

    int need[128] = {0};
    int required = 0;
    for (const char *p = t; *p; p++) {
        if (need[(unsigned char)*p]++ == 0) required++;
    }

    int have[128] = {0};
    int formed = 0;
    int bestLen = n + 1, bestStart = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        unsigned char c = (unsigned char)s[right];
        have[c]++;
        if (need[c] && have[c] == need[c]) formed++;

        while (formed == required) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
            unsigned char lc = (unsigned char)s[left];
            have[lc]--;
            if (need[lc] && have[lc] < need[lc]) formed--;
            left++;
        }
    }

    for (int i = bestStart; i < bestStart + bestLen; i++) {
        putchar(s[i]);
    }
    printf("\n");
    return 0;
}
