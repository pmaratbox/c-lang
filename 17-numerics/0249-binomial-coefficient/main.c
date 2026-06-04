#include <stdio.h>

int main(void) {
    int n = 5, k = 2;
    if (k > n - k) k = n - k;
    long result = 1;
    for (int i = 0; i < k; i++) {
        result = result * (n - i) / (i + 1);
    }
    printf("%ld\n", result);
    return 0;
}
