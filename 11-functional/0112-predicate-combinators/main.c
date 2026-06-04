#include <stdio.h>
#include <stdbool.h>

/* Predicates are function pointers; combinators take two and return
   their combination via a small helper that holds both. */
typedef bool (*Pred)(int);

bool is_even(int n) { return n % 2 == 0; }
bool is_positive(int n) { return n > 0; }

bool and_pred(Pred a, Pred b, int n) {
    return a(n) && b(n);
}

int main(void) {
    bool first = and_pred(is_even, is_positive, 4);
    bool second = and_pred(is_even, is_positive, -4);
    printf("%s %s\n", first ? "yes" : "no", second ? "yes" : "no");
    return 0;
}
