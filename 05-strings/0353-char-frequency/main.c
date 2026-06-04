#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s = "aab";
    char order[256];
    int count[256];
    size_t n = 0;

    for (size_t i = 0; s[i] != '\0'; i++) {
        unsigned char c = (unsigned char)s[i];
        size_t j;
        for (j = 0; j < n; j++) {
            if ((unsigned char)order[j] == c) {
                count[j]++;
                break;
            }
        }
        if (j == n) {
            order[n] = (char)c;
            count[n] = 1;
            n++;
        }
    }

    for (size_t j = 0; j < n; j++) {
        printf("%c:%d", order[j], count[j]);
        if (j + 1 < n) printf(" ");
    }
    printf("\n");
    return 0;
}
