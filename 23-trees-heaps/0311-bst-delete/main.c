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

static Node *min_node(Node *n) {
    while (n->left) n = n->left;
    return n;
}

static Node *delete(Node *root, int v) {
    if (!root) return NULL;
    if (v < root->val) root->left = delete(root->left, v);
    else if (v > root->val) root->right = delete(root->right, v);
    else {
        if (!root->left) { Node *r = root->right; free(root); return r; }
        if (!root->right) { Node *l = root->left; free(root); return l; }
        Node *succ = min_node(root->right);
        root->val = succ->val;
        root->right = delete(root->right, succ->val);
    }
    return root;
}

static void inorder(Node *n, int *first) {
    if (!n) return;
    inorder(n->left, first);
    if (*first) { printf("%d", n->val); *first = 0; }
    else printf(" %d", n->val);
    inorder(n->right, first);
}

int main(void) {
    int keys[] = {5, 3, 8, 1, 4};
    Node *root = NULL;
    for (int i = 0; i < 5; i++) root = insert(root, keys[i]);
    root = delete(root, 3);
    int first = 1;
    inorder(root, &first);
    printf("\n");
    return 0;
}
