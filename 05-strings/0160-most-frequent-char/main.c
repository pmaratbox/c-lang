#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s = "hello";
    int counts[256] = {0};
    for (const char *p = s; *p; p++) {
        counts[(unsigned char)*p]++;
    }
    unsigned char best = (unsigned char)s[0];
    int best_count = 0;
    for (const char *p = s; *p; p++) {
        unsigned char c = (unsigned char)*p;
        if (counts[c] > best_count) {
            best_count = counts[c];
            best = c;
        }
    }
    printf("%c\n", best);
    return 0;
}
