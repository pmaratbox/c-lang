#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

void visit(const Node *n, int *sum) {
    if (n == NULL) {
        return;
    }
    *sum += n->value;
    visit(n->left, sum);
    visit(n->right, sum);
}

int main(void) {
    Node leaf2 = {2, NULL, NULL};
    Node leaf3 = {3, NULL, NULL};
    Node root = {1, &leaf2, &leaf3};
    int sum = 0;
    visit(&root, &sum);
    printf("%d\n", sum);
    return 0;
}
