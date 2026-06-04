#include <stdio.h>
#include <ctype.h>

int main(void) {
    const char *s = "hello_world";
    char out[64];
    size_t o = 0;
    int capitalize = 0;

    for (size_t i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '_') {
            capitalize = 1;
            continue;
        }
        if (capitalize) {
            out[o++] = (char)toupper((unsigned char)c);
            capitalize = 0;
        } else {
            out[o++] = c;
        }
    }
    out[o] = '\0';

    printf("%s\n", out);
    return 0;
}
