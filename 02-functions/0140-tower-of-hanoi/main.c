#include <stdio.h>

static int moves(int n) {
    if (n == 0) {
        return 0;
    }
    return 2 * moves(n - 1) + 1;
}

int main(void) {
    printf("%d\n", moves(3));
    return 0;
}
