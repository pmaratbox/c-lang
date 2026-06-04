#include <stdio.h>

typedef struct Handler {
    int level;
    struct Handler *next;
} Handler;

void handle(Handler *h, int request) {
    if (h == NULL) {
        return;
    }
    if (h->level == request) {
        printf("handled by %d\n", h->level);
    } else {
        handle(h->next, request);
    }
}

int main(void) {
    Handler h3 = {3, NULL};
    Handler h2 = {2, &h3};
    Handler h1 = {1, &h2};
    handle(&h1, 2);
    return 0;
}
