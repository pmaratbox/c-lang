#include <stdio.h>
#include <stdbool.h>

struct Pair {
    int a;
    int b;
};

struct Nested {
    struct Pair left;
    struct Pair right;
};

bool pair_eq(struct Pair x, struct Pair y) {
    return x.a == y.a && x.b == y.b;
}

bool nested_eq(struct Nested x, struct Nested y) {
    return pair_eq(x.left, y.left) && pair_eq(x.right, y.right);
}

int main(void) {
    struct Nested p = { { 1, 2 }, { 3, 4 } };
    struct Nested q = { { 1, 2 }, { 3, 4 } };
    printf("equal: %s\n", nested_eq(p, q) ? "yes" : "no");
    return 0;
}
