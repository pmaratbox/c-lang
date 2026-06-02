#include <stdio.h>

static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static void quicksort(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int pivot = a[hi];
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (a[j] < pivot) {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[hi]);
    quicksort(a, lo, i - 1);
    quicksort(a, i + 1, hi);
}

int main(void) {
    int data[] = {3, 1, 4, 1, 5, 2};
    int n = 6;
    quicksort(data, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", data[i]);
    }
    printf("\n");
    return 0;
}
