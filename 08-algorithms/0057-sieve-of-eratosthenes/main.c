#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n = 10;
    bool is_prime[11];
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int first = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            if (!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
