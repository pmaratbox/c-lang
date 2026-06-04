#include <stdio.h>
#include <stdlib.h>

typedef enum { NUM, ADD, MUL } Kind;

typedef struct Node {
    Kind kind;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

static Node *num(int v) {
    Node *n = malloc(sizeof(Node));
    n->kind = NUM;
    n->value = v;
    n->left = n->right = NULL;
    return n;
}

static Node *binop(Kind k, Node *l, Node *r) {
    Node *n = malloc(sizeof(Node));
    n->kind = k;
    n->left = l;
    n->right = r;
    return n;
}

static int eval(Node *n) {
    switch (n->kind) {
        case NUM: return n->value;
        case ADD: return eval(n->left) + eval(n->right);
        case MUL: return eval(n->left) * eval(n->right);
    }
    return 0;
}

int main(void) {
    /* 1 + 2 * 3 */
    Node *ast = binop(ADD, num(1), binop(MUL, num(2), num(3)));
    printf("%d\n", eval(ast));
    return 0;
}
