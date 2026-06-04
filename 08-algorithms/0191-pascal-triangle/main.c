#include <stdio.h>

int main(void) {
    int rows = 4;
    int prev[4];
    for (int r = 0; r < rows; r++) {
        int cur[4];
        for (int c = 0; c <= r; c++) {
            if (c == 0 || c == r) cur[c] = 1;
            else cur[c] = prev[c - 1] + prev[c];
            printf("%d", cur[c]);
            if (c < r) printf(" ");
        }
        printf("\n");
        for (int c = 0; c <= r; c++) prev[c] = cur[c];
    }
    return 0;
}
