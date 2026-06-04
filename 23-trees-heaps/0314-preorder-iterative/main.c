#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

static Node *make(int v) {
    Node *n = malloc(sizeof *n);
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

static Node *insert(Node *root, int v) {
    if (!root) return make(v);
    if (v < root->val) root->left = insert(root->left, v);
    else if (v > root->val) root->right = insert(root->right, v);
    return root;
}

int main(void) {
    int keys[] = {5, 3, 8, 1, 4};
    Node *root = NULL;
    for (int i = 0; i < 5; i++) root = insert(root, keys[i]);

    Node *stack[16];
    int sp = 0, first = 1;
    stack[sp++] = root;
    while (sp > 0) {
        Node *n = stack[--sp];
        if (first) { printf("%d", n->val); first = 0; }
        else printf(" %d", n->val);
        if (n->right) stack[sp++] = n->right;
        if (n->left) stack[sp++] = n->left;
    }
    printf("\n");
    return 0;
}
