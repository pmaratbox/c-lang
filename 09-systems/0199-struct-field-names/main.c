#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int main(void) {
    /* C has no reflection: list the field names by hand in declaration order */
    const char *fields[] = { "x", "y" };
    size_t n = sizeof(fields) / sizeof(fields[0]);
    for (size_t i = 0; i < n; i++) {
        printf("%s", fields[i]);
        if (i + 1 < n) printf(" ");
    }
    printf("\n");
    return 0;
}
