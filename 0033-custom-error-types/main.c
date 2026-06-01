#include <stdio.h>

enum Error { OK, TOO_LARGE };

enum Error check(int n) {
    if (n > 100) {
        return TOO_LARGE;
    }
    return OK;
}

int main(void) {
    if (check(200) == TOO_LARGE) {
        printf("error: value too large\n");
    }
    return 0;
}
