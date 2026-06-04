#include <stdio.h>

int main(void) {
    int a[] = {1, 2, 3};
    const char *b[] = {"a", "b"};
    int na = 3, nb = 2;
    int n = na > nb ? na : nb;

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        if (i < na) printf("%d", a[i]);
        else printf("-");
        if (i < nb) printf("%s", b[i]);
        else printf("-");
    }
    printf("\n");
    return 0;
}
