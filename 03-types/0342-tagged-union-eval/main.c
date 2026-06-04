#include <stdio.h>
#include <stdlib.h>

typedef enum { NUM, ADD } Tag;

typedef struct Expr {
    Tag tag;
    union {
        int num;
        struct {
            struct Expr *left;
            struct Expr *right;
        } add;
    } as;
} Expr;

static Expr *num(int n) {
    Expr *e = malloc(sizeof(Expr));
    e->tag = NUM;
    e->as.num = n;
    return e;
}

static Expr *add(Expr *l, Expr *r) {
    Expr *e = malloc(sizeof(Expr));
    e->tag = ADD;
    e->as.add.left = l;
    e->as.add.right = r;
    return e;
}

static int eval(Expr *e) {
    switch (e->tag) {
        case NUM: return e->as.num;
        case ADD: return eval(e->as.add.left) + eval(e->as.add.right);
    }
    return 0;
}

int main(void) {
    Expr *expr = add(num(1), num(2));
    printf("%d\n", eval(expr));
    return 0;
}
