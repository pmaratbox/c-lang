#include <stdio.h>

int main(void) {
    const char *s = "Hi";
    int first = 1;
    for (const unsigned char *p = (const unsigned char *)s; *p; p++) {
        if (!first) printf(" ");
        printf("%02x", *p);
        first = 0;
    }
    printf("\n");
    return 0;
}
