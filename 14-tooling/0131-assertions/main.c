#include <stdio.h>
#include <stdlib.h>

static void check(int cond, const char *msg) {
    if (!cond) {
        fprintf(stderr, "assertion failed: %s\n", msg);
        exit(1);
    }
}

int main(void) {
    check(1 + 1 == 2, "1+1==2");
    check(2 * 3 == 6, "2*3==6");
    check(10 - 4 == 6, "10-4==6");
    printf("all passed\n");
    return 0;
}
