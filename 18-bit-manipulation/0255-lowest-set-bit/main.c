#include <stdio.h>

int main(void) {
    unsigned x = 12;
    unsigned low = x & (~x + 1);
    printf("%u\n", low);
    return 0;
}
