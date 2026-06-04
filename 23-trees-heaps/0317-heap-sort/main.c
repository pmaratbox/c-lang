#include <stdio.h>

static void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

static void sift_down(int *a, int i, int n) {
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, big = i;
        if (l < n && a[l] > a[big]) big = l;
        if (r < n && a[r] > a[big]) big = r;
        if (big == i) break;
        swap(&a[i], &a[big]);
        i = big;
    }
}

static void heap_sort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) sift_down(a, i, n);
    for (int end = n - 1; end > 0; end--) {
        swap(&a[0], &a[end]);
        sift_down(a, 0, end);
    }
}

int main(void) {
    int a[] = {5, 3, 8, 1, 4};
    int n = 5;
    heap_sort(a, n);
    for (int i = 0; i < n; i++)
        printf(i ? " %d" : "%d", a[i]);
    printf("\n");
    return 0;
}
