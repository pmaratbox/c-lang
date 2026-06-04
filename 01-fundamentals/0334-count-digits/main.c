#include <stdio.h>

int main(void) {
    int n = 90210;
    int count = 0;
    do {
        count++;
        n /= 10;
    } while (n != 0);
    printf("%d\n", count);
    return 0;
}
