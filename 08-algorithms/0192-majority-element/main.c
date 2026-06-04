#include <stdio.h>

int main(void) {
    int a[] = {2, 2, 1, 2, 3, 2};
    int n = 6;
    int candidate = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) candidate = a[i];
        count += (a[i] == candidate) ? 1 : -1;
    }
    printf("%d\n", candidate);
    return 0;
}
