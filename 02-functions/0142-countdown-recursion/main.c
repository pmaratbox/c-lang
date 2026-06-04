#include <stdio.h>

static void countdown(int n) {
    if (n < 1) {
        return;
    }
    printf("%d", n);
    if (n > 1) {
        printf(" ");
    }
    countdown(n - 1);
}

int main(void) {
    countdown(5);
    printf("\n");
    return 0;
}
