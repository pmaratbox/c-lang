#include <stdio.h>
#include <string.h>

int largest_int(int a, int b) {
    return a > b ? a : b;
}

const char *largest_str(const char *a, const char *b) {
    return strcmp(a, b) > 0 ? a : b;
}

#define largest(a, b) _Generic((a), \
    int: largest_int, \
    const char *: largest_str, \
    char *: largest_str \
)(a, b)

int main(void) {
    printf("%d\n", largest(3, 9));
    const char *x = "apple";
    const char *y = "pear";
    printf("%s\n", largest(x, y));
    return 0;
}
