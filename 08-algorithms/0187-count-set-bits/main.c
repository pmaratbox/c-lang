#include <stdio.h>

int main(void) {
    unsigned int n = 13;
    int count = 0;
    while (n != 0) {
        n &= n - 1;
        count++;
    }
    printf("%d\n", count);
    return 0;
}
