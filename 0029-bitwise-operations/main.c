#include <stdio.h>

int main(void) {
    int a = 6, b = 3;
    printf("and: %d\n", a & b);
    printf("or: %d\n", a | b);
    printf("xor: %d\n", a ^ b);
    printf("shift: %d\n", a << 1);
    return 0;
}
