#include <stdio.h>

int main(void) {
    const char *word = "banana";
    int counts[256] = {0};
    for (const char *p = word; *p; p++) {
        counts[(unsigned char)*p]++;
    }

    int first = 1;
    for (int c = 0; c < 256; c++) {
        if (counts[c] > 0) {
            if (!first) printf(" ");
            printf("%c:%d", c, counts[c]);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
