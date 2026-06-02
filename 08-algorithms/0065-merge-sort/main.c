#include <stdio.h>

static void merge(int *items, int lo, int mid, int hi, int *buf) {
    int i = lo, j = mid, k = lo;
    while (i < mid && j < hi) {
        if (items[i] <= items[j]) buf[k++] = items[i++];
        else buf[k++] = items[j++];
    }
    while (i < mid) buf[k++] = items[i++];
    while (j < hi) buf[k++] = items[j++];
    for (int t = lo; t < hi; t++) items[t] = buf[t];
}

static void merge_sort(int *items, int lo, int hi, int *buf) {
    if (hi - lo <= 1) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort(items, lo, mid, buf);
    merge_sort(items, mid, hi, buf);
    merge(items, lo, mid, hi, buf);
}

int main(void) {
    int data[] = {3, 1, 4, 1, 5, 2};
    int n = (int)(sizeof(data) / sizeof(data[0]));
    int buf[6];
    merge_sort(data, 0, n, buf);

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", data[i]);
    }
    printf("\n");
    return 0;
}
