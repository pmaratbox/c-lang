#include <stdio.h>

static int has(const int *set, int v) {
    for (int i = 0; i < 3; i++) {
        if (set[i] == v) return 1;
    }
    return 0;
}

int main(void) {
    int a[] = {1, 2, 3};
    int b[] = {2, 3, 4};

    int first = 1;
    for (int v = 1; v <= 4; v++) {
        if (has(a, v) || has(b, v)) {
            if (!first) printf(" ");
            printf("%d", v);
            first = 0;
        }
    }
    printf("\n");

    first = 1;
    for (int v = 1; v <= 4; v++) {
        if (has(a, v) && has(b, v)) {
            if (!first) printf(" ");
            printf("%d", v);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
