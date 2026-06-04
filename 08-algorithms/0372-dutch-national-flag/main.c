#include <stdio.h>

static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int a[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (a[mid] == 0) swap(&a[low++], &a[mid++]);
        else if (a[mid] == 1) mid++;
        else swap(&a[mid], &a[high--]);
    }
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i + 1 < n ? " " : "\n");
    return 0;
}
