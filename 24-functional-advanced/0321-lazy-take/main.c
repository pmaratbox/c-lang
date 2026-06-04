#include <stdio.h>

/* A lazy natural-number stream is just a stateful generator: each pull
   returns the next value and advances the internal counter. */
typedef struct {
    int next;
} Naturals;

static int pull(Naturals *s) {
    return s->next++;
}

int main(void) {
    Naturals nats = {1};
    for (int i = 0; i < 5; i++) {
        printf("%d", pull(&nats));
        if (i < 4) printf(" ");
    }
    printf("\n");
    return 0;
}
