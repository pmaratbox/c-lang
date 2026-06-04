#include <stdio.h>

/* Model [1,[2,[3,4]],5] as a tree of nodes: a node is either a scalar
   leaf or a list of child nodes. */

typedef struct Node {
    int is_list;
    int value;             /* used when is_list == 0 */
    struct Node **kids;    /* used when is_list == 1 */
    int nkids;
} Node;

static Node leaf_v(int v) { return (Node){0, v, NULL, 0}; }

static int first = 1;

static void flatten(const Node *n) {
    if (!n->is_list) {
        if (!first) printf(" ");
        printf("%d", n->value);
        first = 0;
        return;
    }
    for (int i = 0; i < n->nkids; i++)
        flatten(n->kids[i]);
}

int main(void) {
    /* [3,4] */
    Node l3 = leaf_v(3), l4 = leaf_v(4);
    Node *inner_kids[] = {&l3, &l4};
    Node inner = {1, 0, inner_kids, 2};

    /* [2,[3,4]] */
    Node l2 = leaf_v(2);
    Node *mid_kids[] = {&l2, &inner};
    Node mid = {1, 0, mid_kids, 2};

    /* [1,[2,[3,4]],5] */
    Node l1 = leaf_v(1), l5 = leaf_v(5);
    Node *root_kids[] = {&l1, &mid, &l5};
    Node root = {1, 0, root_kids, 3};

    flatten(&root);
    printf("\n");
    return 0;
}
