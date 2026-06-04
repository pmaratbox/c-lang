#include <stdio.h>

/* C has no exceptions; model a tagged error matched by category. */
enum ErrorKind { ERR_BASE, ERR_SPECIFIC };

static enum ErrorKind category(enum ErrorKind k) {
    /* a specific error belongs to the base category */
    return (k == ERR_SPECIFIC) ? ERR_BASE : k;
}

int main(void) {
    enum ErrorKind thrown = ERR_SPECIFIC;
    if (category(thrown) == ERR_BASE) {
        printf("caught base\n");
    }
    return 0;
}
