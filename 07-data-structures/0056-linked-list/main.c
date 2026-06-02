#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

static Node *make(int value, Node *next) {
    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->next = next;
    return n;
}

int main(void) {
    Node *head = make(1, make(2, make(3, NULL)));

    for (Node *node = head; node != NULL; node = node->next) {
        printf("%d", node->value);
        if (node->next != NULL) printf(" -> ");
    }
    printf("\n");

    Node *node = head;
    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }
    return 0;
}
