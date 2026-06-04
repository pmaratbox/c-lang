#include <stdio.h>

int lower_bound(const int *a, int n, int key) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < key) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int upper_bound(const int *a, int n, int key) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] <= key) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main(void) {
    int a[] = {1, 3, 5, 5, 7};
    int n = sizeof(a) / sizeof(a[0]);
    printf("%d %d\n", lower_bound(a, n, 5), upper_bound(a, n, 5));
    return 0;
}
