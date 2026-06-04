#include <stdio.h>
#include <string.h>

int main(void) {
    const char *col1[] = { "a", "bb" };
    const char *col2[] = { "1", "22" };
    size_t rows = 2;

    size_t width = 0;
    for (size_t i = 0; i < rows; i++) {
        size_t len = strlen(col1[i]);
        if (len > width) {
            width = len;
        }
    }

    for (size_t i = 0; i < rows; i++) {
        printf("%-*s | %s\n", (int)width, col1[i], col2[i]);
    }
    return 0;
}
