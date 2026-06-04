#include <stdio.h>
#include <string.h>

static const char TABLE[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main(void) {
    const char *in = "hi";
    size_t len = strlen(in);

    char out[64];
    size_t o = 0;

    for (size_t i = 0; i < len; i += 3) {
        unsigned b0 = (unsigned char)in[i];
        unsigned b1 = i + 1 < len ? (unsigned char)in[i + 1] : 0;
        unsigned b2 = i + 2 < len ? (unsigned char)in[i + 2] : 0;
        unsigned triple = (b0 << 16) | (b1 << 8) | b2;

        out[o++] = TABLE[(triple >> 18) & 0x3F];
        out[o++] = TABLE[(triple >> 12) & 0x3F];
        out[o++] = i + 1 < len ? TABLE[(triple >> 6) & 0x3F] : '=';
        out[o++] = i + 2 < len ? TABLE[triple & 0x3F] : '=';
    }
    out[o] = '\0';

    printf("%s\n", out);
    return 0;
}
