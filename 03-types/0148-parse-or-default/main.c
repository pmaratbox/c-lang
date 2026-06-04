#include <stdio.h>
#include <stdlib.h>

int parse_or_default(const char *s, int fallback) {
    char *end;
    long v = strtol(s, &end, 10);
    if (end == s || *end != '\0') {
        return fallback;
    }
    return (int)v;
}

int main(void) {
    int a = parse_or_default("42", 0);
    int b = parse_or_default("x", 0);
    printf("%d %d\n", a, b);
    return 0;
}
