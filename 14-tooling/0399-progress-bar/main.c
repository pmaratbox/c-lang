#include <stdio.h>
#include <math.h>

int main(void) {
    int width = 10;
    double pct = 0.4;
    int filled = (int)round(width * pct);

    printf("[");
    for (int i = 0; i < filled; i++) {
        printf("#");
    }
    for (int i = filled; i < width; i++) {
        printf("-");
    }
    printf("]\n");
    return 0;
}
