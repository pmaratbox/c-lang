#include <stdio.h>

int main(void) {
    const char *s = "aabbcc";
    int seen[256] = {0};
    for (const char *p = s; *p; p++) {
        unsigned char c = (unsigned char)*p;
        if (!seen[c]) {
            seen[c] = 1;
            putchar(c);
        }
    }
    printf("\n");
    return 0;
}
