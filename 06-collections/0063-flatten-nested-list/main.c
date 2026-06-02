#include <stdio.h>

int main(void) {
    int nested[2][2] = {{1, 2}, {3, 4}};
    int rows = 2, cols = 2;

    int first = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!first) printf(" ");
            printf("%d", nested[i][j]);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
