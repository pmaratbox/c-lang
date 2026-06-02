#include <stdio.h>

int divide(int a, int b, int *result) {
    if (b == 0) {
        return -1;
    }
    *result = a / b;
    return 0;
}

int main(void) {
    int result;

    if (divide(10, 2, &result) == 0) {
        printf("10 / 2 = %d\n", result);
    } else {
        printf("error: division by zero\n");
    }

    if (divide(10, 0, &result) != 0) {
        printf("error: division by zero\n");
    }
    return 0;
}
