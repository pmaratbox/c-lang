#include <stdio.h>

int main(void) {
    const char *inner = "inner";
    const char *outer = "outer";
    printf("%s: %s\n", outer, inner); /* wrap inner with outer context */
    return 0;
}
