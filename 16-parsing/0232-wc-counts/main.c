#include <stdio.h>
#include <ctype.h>

int main(void) {
    const char *s = "a b\nc";
    int chars = 0, lines = 1, words = 0;
    int in_word = 0;
    for (const char *p = s; *p; p++) {
        chars++;
        if (*p == '\n') lines++;
        if (isspace((unsigned char)*p)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    printf("%d %d %d\n", words, lines, chars);
    return 0;
}
