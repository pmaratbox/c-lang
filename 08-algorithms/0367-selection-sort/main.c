#include <stdio.h>

int main(void) {
    int a[] = {5, 1, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i + 1 < n ? " " : "\n");
    return 0;
}
