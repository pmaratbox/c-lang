#include <stdio.h>

int main(void) {
    int n = 7;

    if (n < 10) {
        printf("%d is less than 10\n", n);
    } else if (n == 10) {
        printf("%d is equal to 10\n", n);
    } else {
        printf("%d is greater than 10\n", n);
    }
    return 0;
}
