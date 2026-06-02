#include <stdio.h>
#include <stdlib.h>

int asc_cmp(const void *a, const void *b) {
    return (*(const int *)a) - (*(const int *)b);
}

int desc_cmp(const void *a, const void *b) {
    return (*(const int *)b) - (*(const int *)a);
}

void print_row(const char *label, const int *arr, size_t n) {
    printf("%s:", label);
    for (size_t i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int asc[] = {3, 1, 2};
    int desc[] = {3, 1, 2};
    size_t n = 3;
    qsort(asc, n, sizeof(int), asc_cmp);
    qsort(desc, n, sizeof(int), desc_cmp);
    print_row("asc", asc, n);
    print_row("desc", desc, n);
    return 0;
}
