#include <stdio.h>

/* A fixed-point combinator lets a non-recursive generator call itself
   without naming itself. C has no closures, so fix passes the generator
   a self-reference (a function pointer) it can re-invoke via fix. */
typedef int (*SelfFn)(int);
typedef int (*Gen)(SelfFn, int);

static Gen g_gen;          /* the generator under fixation */

static int self_apply(int n) {
    return g_gen(self_apply, n);   /* re-enters the generator: this is the fix point */
}

static int fix(Gen gen, int n) {
    g_gen = gen;
    return self_apply(n);
}

/* non-recursive factorial generator: recurses only through self */
static int fact_gen(SelfFn self, int n) {
    return n == 0 ? 1 : n * self(n - 1);
}

int main(void) {
    printf("%d\n", fix(fact_gen, 5));
    return 0;
}
