#include <stdio.h>

static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static int partition(int *a, int lo, int hi) {
    int pivot = a[hi];
    int i = lo;
    for (int j = lo; j < hi; j++)
        if (a[j] < pivot) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    return i;
}

static int quickselect(int *a, int lo, int hi, int k) {
    while (lo < hi) {
        int p = partition(a, lo, hi);
        if (p == k) return a[p];
        if (p < k) lo = p + 1;
        else hi = p - 1;
    }
    return a[lo];
}

int main(void) {
    int a[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(a) / sizeof(a[0]);
    printf("%d\n", quickselect(a, 0, n - 1, 2));
    return 0;
}
