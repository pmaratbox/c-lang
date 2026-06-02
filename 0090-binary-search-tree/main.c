#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

static Node *insert(Node *root, int value) {
    if (root == NULL) {
        Node *n = malloc(sizeof(Node));
        n->value = value;
        n->left = n->right = NULL;
        return n;
    }
    if (value < root->value) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

static int first = 1;

static void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    if (!first) printf(" ");
    printf("%d", root->value);
    first = 0;
    inorder(root->right);
}

int main(void) {
    int vals[] = {5, 3, 8, 1, 4};
    Node *root = NULL;
    for (int i = 0; i < 5; i++) root = insert(root, vals[i]);
    inorder(root);
    printf("\n");
    return 0;
}
