#include <stdio.h>

int main(void) {
    int a[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(a) / sizeof(a[0]);
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int tmp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > tmp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i + 1 < n ? " " : "\n");
    return 0;
}
