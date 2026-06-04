#include <stdio.h>

int main(void) {
    int a[] = {1, 1, 2, 3, 3, 3};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n;) {
        if (i > 0) printf("|");
        int j = i;
        while (j < n && a[j] == a[i]) {
            if (j > i) printf(" ");
            printf("%d", a[j]);
            j++;
        }
        i = j;
    }
    printf("\n");
    return 0;
}
