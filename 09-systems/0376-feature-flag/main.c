#include <stdio.h>

static const char *describe(int flag) {
    return flag ? "enabled" : "disabled";
}

int main(void) {
    printf("%s %s\n", describe(1), describe(0));
    return 0;
}
