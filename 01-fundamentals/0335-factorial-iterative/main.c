#include <stdio.h>

int main(void) {
    long result = 1;
    for (int i = 1; i <= 5; i++) {
        result *= i;
    }
    printf("%ld\n", result);
    return 0;
}
