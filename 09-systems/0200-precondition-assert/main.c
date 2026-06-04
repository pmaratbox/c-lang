#include <stdio.h>

static void check(int arg) {
    if (arg > 0) {
        printf("ok\n");
    } else {
        printf("error: must be positive\n");
    }
}

int main(void) {
    check(5);
    check(-1);
    return 0;
}
