#include <stdio.h>

int main(void) {
    int n = 60;
    int first = 1;
    while (n % 2 == 0) {
        printf(first ? "%d" : " %d", 2);
        first = 0;
        n /= 2;
    }
    for (int i = 3; (long)i * i <= n; i += 2) {
        while (n % i == 0) {
            printf(first ? "%d" : " %d", i);
            first = 0;
            n /= i;
        }
    }
    if (n > 1) {
        printf(first ? "%d" : " %d", n);
    }
    printf("\n");
    return 0;
}
