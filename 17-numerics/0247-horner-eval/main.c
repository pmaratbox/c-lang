#include <stdio.h>

int main(void) {
    int coeffs[] = {2, 3, 1};
    int n = sizeof(coeffs) / sizeof(coeffs[0]);
    int x = 2;
    int result = 0;
    for (int i = 0; i < n; i++)
        result = result * x + coeffs[i];
    printf("%d\n", result);
    return 0;
}
