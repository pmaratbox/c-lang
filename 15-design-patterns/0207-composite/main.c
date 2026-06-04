#include <stdio.h>

typedef struct Node {
    int value;
    struct Node **children;
    int count;
} Node;

int size(const Node *n) {
    if (n->count == 0) {
        return n->value;
    }
    int total = 0;
    for (int i = 0; i < n->count; i++) {
        total += size(n->children[i]);
    }
    return total;
}

int main(void) {
    Node a = {1, NULL, 0};
    Node b = {2, NULL, 0};
    Node c = {3, NULL, 0};
    Node *kids[] = {&a, &b, &c};
    Node root = {0, kids, 3};
    printf("%d\n", size(&root));
    return 0;
}
