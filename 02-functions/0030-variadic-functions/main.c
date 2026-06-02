#include <stdarg.h>
#include <stdio.h>

int total(int count, ...) {
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

int main(void) {
    printf("sum: %d\n", total(3, 1, 2, 3));
    return 0;
}
