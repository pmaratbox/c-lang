#include <stdio.h>

int main(void) {
    int a[] = {1, 2, 3};
    int n = 3;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (mask == 0) {
            printf("{}\n");
            continue;
        }
        int first = 1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                printf(first ? "%d" : " %d", a[i]);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
