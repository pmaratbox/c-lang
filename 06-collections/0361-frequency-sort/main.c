#include <stdio.h>

int main(void) {
    int a[] = {1, 1, 2, 3, 3, 3};
    int n = 6;

    /* Distinct values in first-seen order, with counts. */
    int vals[16], counts[16], k = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (; j < k; j++) {
            if (vals[j] == a[i]) { counts[j]++; break; }
        }
        if (j == k) { vals[k] = a[i]; counts[k] = 1; k++; }
    }

    /* Stable sort by count descending: insertion sort preserves first-seen
       order on ties (only strictly-greater counts move ahead). */
    for (int i = 1; i < k; i++) {
        int tv = vals[i], tc = counts[i];
        int j = i - 1;
        while (j >= 0 && counts[j] < tc) {
            vals[j + 1] = vals[j];
            counts[j + 1] = counts[j];
            j--;
        }
        vals[j + 1] = tv;
        counts[j + 1] = tc;
    }

    int first = 1;
    for (int i = 0; i < k; i++) {
        for (int c = 0; c < counts[i]; c++) {
            if (!first) printf(" ");
            printf("%d", vals[i]);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
