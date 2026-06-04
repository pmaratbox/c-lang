#include <stdio.h>

/* Continuation-passing style: each step takes a continuation k that
   receives the result. We thread the accumulated multiplier as the
   continuation state, ending with the identity continuation. */
static int fact_cps(int n, int k) {
    if (n == 0) return k;          /* apply the accumulated continuation */
    return fact_cps(n - 1, k * n); /* tail call passes the new continuation */
}

int main(void) {
    printf("%d\n", fact_cps(5, 1)); /* identity continuation seed = 1 */
    return 0;
}
