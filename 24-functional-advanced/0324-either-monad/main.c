#include <stdio.h>

/* Either is a tagged union of Right (ok value) and Left (error tag).
   bind runs the next step only on Right, short-circuiting on Left. */
typedef struct {
    int is_right;
    int value;
    const char *err;
} Either;

static Either right(int v)            { Either e = {1, v, ""};  return e; }
static Either left(const char *tag)   { Either e = {0, 0, tag}; return e; }

static Either bind(Either e, Either (*f)(int)) {
    return e.is_right ? f(e.value) : e;
}

/* divide x by 2, failing on a zero divisor encoded as a sentinel */
static Either half(int x)   { return right(x / 2); }
static Either div0(int x)   { (void)x; return left("err"); }

int main(void) {
    Either ok  = bind(bind(right(8), half), half);   /* 8 -> 4 -> 2 */
    Either bad = bind(bind(right(8), div0), half);   /* Left short-circuits */
    if (ok.is_right) printf("%d", ok.value); else printf("%s", ok.err);
    printf(" ");
    if (bad.is_right) printf("%d", bad.value); else printf("%s", bad.err);
    printf("\n");
    return 0;
}
