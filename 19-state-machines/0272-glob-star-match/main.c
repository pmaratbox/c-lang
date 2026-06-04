#include <stdio.h>

static int match(const char *pat, const char *txt) {
    if (*pat == '\0')
        return *txt == '\0';
    if (*pat == '*') {
        /* zero or more chars */
        if (match(pat + 1, txt))
            return 1;
        if (*txt && match(pat, txt + 1))
            return 1;
        return 0;
    }
    if (*txt && *pat == *txt)
        return match(pat + 1, txt + 1);
    return 0;
}

int main(void) {
    printf("%s ", match("a*b", "aaab") ? "yes" : "no");
    printf("%s\n", match("a*b", "aac") ? "yes" : "no");
    return 0;
}
