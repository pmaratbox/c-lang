#include <stdio.h>

static int a[] = {1, 2, 3};
static int n = 3;
static int used[3];
static int perm[3];

static void rec(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", perm[i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            perm[depth] = a[i];
            rec(depth + 1);
            used[i] = 0;
        }
    }
}

int main(void) {
    rec(0);
    return 0;
}
