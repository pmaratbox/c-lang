#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n = 42;
    double pi = 3.14;
    const char *greeting = "hello";
    bool flag = true;

    printf("int: %d\n", n);
    printf("float: %g\n", pi);
    printf("string: %s\n", greeting);
    printf("bool: %s\n", flag ? "true" : "false");
    return 0;
}
