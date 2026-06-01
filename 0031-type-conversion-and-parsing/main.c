#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = atoi("42");
    double f = atof("3.5");
    char s[16];
    snprintf(s, sizeof(s), "%d", n);
    printf("int: %d\n", n);
    printf("float: %g\n", f);
    printf("str: %s\n", s);
    return 0;
}
