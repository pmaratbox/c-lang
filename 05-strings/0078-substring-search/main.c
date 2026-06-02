#include <stdio.h>
#include <string.h>

int main(void) {
    const char *text = "hello";
    const char *p = strstr(text, "lo");
    printf("%ld\n", (long)(p - text));
    return 0;
}
