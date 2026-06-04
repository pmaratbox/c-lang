#include <stdio.h>
#include <string.h>

static void rot13(const char *in, char *out) {
    size_t i;
    for (i = 0; in[i] != '\0'; i++) {
        char c = in[i];
        if (c >= 'a' && c <= 'z')
            out[i] = (char)('a' + (c - 'a' + 13) % 26);
        else if (c >= 'A' && c <= 'Z')
            out[i] = (char)('A' + (c - 'A' + 13) % 26);
        else
            out[i] = c;
    }
    out[i] = '\0';
}

int main(void) {
    char enc[64];
    char dec[64];
    rot13("hello", enc);
    rot13(enc, dec);
    printf("%s %s\n", enc, dec);
    return 0;
}
