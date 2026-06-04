#include <stdio.h>
#include <ctype.h>

static int unreserved(unsigned char c) {
    return isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~';
}

int main(void) {
    const char *s = "a b&c";
    for (const unsigned char *p = (const unsigned char *)s; *p; p++) {
        if (unreserved(*p)) {
            putchar(*p);
        } else {
            printf("%%%02X", *p);
        }
    }
    printf("\n");
    return 0;
}
