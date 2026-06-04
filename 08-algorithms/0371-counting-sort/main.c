#include <stdio.h>

int main(void) {
    int a[] = {3, 1, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    int count[16] = {0};
    for (int i = 0; i < n; i++)
        count[a[i]]++;
    int first = 1;
    for (int v = 0; v <= max; v++) {
        for (int c = 0; c < count[v]; c++) {
            printf("%s%d", first ? "" : " ", v);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
