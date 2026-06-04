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

static int height(Node *n) {
    if (!n) return 0;
    int l = height(n->left), r = height(n->right);
    return 1 + (l > r ? l : r);
}

int main(void) {
    int keys[] = {5, 3, 8, 1, 4};
    Node *root = NULL;
    for (int i = 0; i < 5; i++) root = insert(root, keys[i]);
    printf("%d\n", height(root));
    return 0;
}
