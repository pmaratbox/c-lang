#include <stdio.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; (long)i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    printf("%s %s\n", is_prime(7) ? "yes" : "no", is_prime(9) ? "yes" : "no");
    return 0;
}
