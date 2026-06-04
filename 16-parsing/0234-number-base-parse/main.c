#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long hex = strtol("ff", NULL, 16);
    long bin = strtol("101", NULL, 2);
    printf("%ld %ld\n", hex, bin);
    return 0;
}
