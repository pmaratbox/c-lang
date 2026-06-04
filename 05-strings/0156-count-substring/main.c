#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s = "ababab";
    const char *needle = "ab";
    size_t len = strlen(needle);
    int count = 0;
    const char *p = s;
    while ((p = strstr(p, needle)) != NULL) {
        count++;
        p += len;
    }
    printf("%d\n", count);
    return 0;
}
