#include <stdio.h>

int main(void) {
    int xs[] = {1, 2, 3, 4, 1};
    int n = sizeof(xs) / sizeof(xs[0]);
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (xs[i] >= 3) {
            break;
        }
        printf(first ? "%d" : " %d", xs[i]);
        first = 0;
    }
    printf("\n");
    return 0;
}
