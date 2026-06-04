#include <stdio.h>

/* flatMap maps each element to a small list (x, x*10) and concatenates
   the results into one flat output buffer. */
int main(void) {
    int xs[] = {1, 2, 3};
    int out[6];
    int k = 0;
    for (int i = 0; i < 3; i++) {
        out[k++] = xs[i];
        out[k++] = xs[i] * 10;
    }
    for (int i = 0; i < k; i++) {
        printf("%d", out[i]);
        if (i < k - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
