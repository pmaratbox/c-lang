#include <stdio.h>

typedef struct Node {
    char name;
    struct Node *left, *right;
} Node;

static int best;

static int height(Node *n) {
    if (!n) return 0;
    int l = height(n->left), r = height(n->right);
    if (l + r > best) best = l + r;
    return 1 + (l > r ? l : r);
}

int main(void) {
    /*        root
              /  \
             A    B
            / \
           C   D   */
    Node C = {'C', NULL, NULL}, D = {'D', NULL, NULL};
    Node A = {'A', &C, &D}, B = {'B', NULL, NULL};
    Node root = {'R', &A, &B};

    best = 0;
    height(&root);
    printf("%d\n", best);
    return 0;
}
