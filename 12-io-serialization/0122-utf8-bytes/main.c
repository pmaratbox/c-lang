#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s = "Hi";
    size_t len = strlen(s);

    for (size_t i = 0; i < len; i++) {
        if (i > 0) printf(" ");
        printf("%d", (unsigned char)s[i]);
    }
    printf("\n");
    return 0;
}
