#include <stdio.h>

/* Maybe is a tagged struct; bind applies f only when present, otherwise
   it propagates the absent value (short-circuiting the chain). */
typedef struct {
    int present;
    int value;
} Maybe;

static Maybe some(int v) { Maybe m = {1, v}; return m; }
static Maybe none(void)  { Maybe m = {0, 0}; return m; }

static Maybe bind(Maybe m, Maybe (*f)(int)) {
    return m.present ? f(m.value) : m;
}

static Maybe add3(int x) { return some(x + 3); }
static Maybe mul2(int x) { return some(x * 2); }

int main(void) {
    Maybe a = bind(bind(some(2), add3), mul2);
    Maybe b = bind(bind(none(), add3), mul2);
    if (a.present) printf("%d", a.value); else printf("none");
    printf(" ");
    if (b.present) printf("%d", b.value); else printf("none");
    printf("\n");
    return 0;
}
