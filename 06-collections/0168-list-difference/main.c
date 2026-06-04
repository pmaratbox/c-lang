#include <stdio.h>

int main(void) {
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 4};
    int an = sizeof(a) / sizeof(a[0]);
    int bn = sizeof(b) / sizeof(b[0]);

    int first = 1;
    for (int i = 0; i < an; i++) {
        int in_b = 0;
        for (int j = 0; j < bn; j++) {
            if (a[i] == b[j]) {
                in_b = 1;
                break;
            }
        }
        if (!in_b) {
            printf(first ? "%d" : " %d", a[i]);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
