#include <stdio.h>

int main(void) {
    const char *spec = "a-e";
    char start = spec[0];
    char end = spec[2];
    char out[64];
    size_t o = 0;

    for (char c = start; c <= end; c++)
        out[o++] = c;
    out[o] = '\0';

    printf("%s\n", out);
    return 0;
}
