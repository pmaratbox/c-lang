#include <stdio.h>

/* trait A */
typedef struct { const char *(*a)(void); } TraitA;
/* trait B */
typedef struct { const char *(*b)(void); } TraitB;

static const char *a_impl(void) { return "a"; }
static const char *b_impl(void) { return "b"; }

/* composed type embeds both traits */
typedef struct {
    TraitA as_a;
    TraitB as_b;
} Composed;

int main(void) {
    Composed c = { { a_impl }, { b_impl } };
    printf("%s %s\n", c.as_a.a(), c.as_b.b());
    return 0;
}
