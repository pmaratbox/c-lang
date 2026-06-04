#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

int main(void) {
    Node *head = NULL, *tail = NULL;
    for (int i = 1; i <= 3; i++) {
        Node *n = malloc(sizeof(Node));
        n->value = i;
        n->prev = tail;
        n->next = NULL;
        if (tail) tail->next = n;
        else head = n;
        tail = n;
    }

    for (Node *p = head; p; p = p->next)
        printf("%d%s", p->value, p->next ? " " : "\n");
    for (Node *p = tail; p; p = p->prev)
        printf("%d%s", p->value, p->prev ? " " : "\n");

    for (Node *p = head; p;) { Node *nx = p->next; free(p); p = nx; }
    return 0;
}
