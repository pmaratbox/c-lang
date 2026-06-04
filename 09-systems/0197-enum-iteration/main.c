#include <stdio.h>

typedef enum { RED, GREEN, BLUE, COLOR_COUNT } Color;

int main(void) {
    const char *names[] = { "RED", "GREEN", "BLUE" };
    for (Color c = RED; c < COLOR_COUNT; c++) {
        printf("%s", names[c]);
        if (c + 1 < COLOR_COUNT) printf(" ");
    }
    printf("\n");
    return 0;
}
