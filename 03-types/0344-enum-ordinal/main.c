#include <stdio.h>

typedef enum { N, E, S, W } Direction;

static const char *names[] = { "N", "E", "S", "W" };

int main(void) {
    Direction s = S;
    printf("%d %s\n", (int)s, names[3]);
    return 0;
}
