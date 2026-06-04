#include <stdio.h>

static int is_pow2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main(void) {
    printf("%s %s\n", is_pow2(16) ? "yes" : "no", is_pow2(18) ? "yes" : "no");
    return 0;
}
