#include <stdio.h>

static int sign(int x) {
    return (x > 0) - (x < 0);
}

int main(void) {
    printf("%d %d %d\n", sign(-5), sign(0), sign(5));
    return 0;
}
