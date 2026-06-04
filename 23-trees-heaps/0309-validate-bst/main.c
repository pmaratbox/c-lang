#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

static bool valid(Node *n, long low, long high) {
    if (!n) return true;
    if (n->val <= low || n->val >= high) return false;
    return valid(n->left, low, n->val) && valid(n->right, n->val, high);
}

int main(void) {
    /* correct BST:      5
                       /   \
                      3     8
                     / \
                    1   4   */
    Node a1 = {1, NULL, NULL}, a4 = {4, NULL, NULL};
    Node a3 = {3, &a1, &a4}, a8 = {8, NULL, NULL};
    Node a5 = {5, &a3, &a8};

    /* invalid BST: node 6 in left subtree of 5 */
    Node b6 = {6, NULL, NULL}, b4 = {4, NULL, NULL};
    Node b3 = {3, &b4, &b6}, b8 = {8, NULL, NULL};
    Node b5 = {5, &b3, &b8};

    printf("%s %s\n",
           valid(&a5, LONG_MIN, LONG_MAX) ? "yes" : "no",
           valid(&b5, LONG_MIN, LONG_MAX) ? "yes" : "no");
    return 0;
}
