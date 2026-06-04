#include <stdio.h>

int main(void) {
    const char *messages[] = { "ok", "denied", "not found" };
    int code = 2;
    printf("%s\n", messages[code]);
    return 0;
}
