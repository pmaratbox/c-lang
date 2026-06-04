#include <stdio.h>

int main(void) {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;
    int cur = a[0];
    int best = a[0];
    for (int i = 1; i < n; i++) {
        cur = a[i] > cur + a[i] ? a[i] : cur + a[i];
        if (cur > best) best = cur;
    }
    printf("%d\n", best);
    return 0;
}
