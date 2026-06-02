#include <stdio.h>

int main(void) {
    int n = 1234;
    int total = 0;
    while (n > 0) {
        total += n % 10;
        n /= 10;
    }
    printf("%d\n", total);
    return 0;
}
