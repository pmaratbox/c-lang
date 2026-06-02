#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    const char *name = "world";

    printf("Hello, %s!\n", name);

    for (size_t i = 0; name[i] != '\0'; i++) {
        putchar(toupper((unsigned char)name[i]));
    }
    putchar('\n');

    printf("length: %zu\n", strlen(name));
    return 0;
}
