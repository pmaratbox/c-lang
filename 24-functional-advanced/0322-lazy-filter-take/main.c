#include <stdio.h>

/* Lazy naturals as a stateful pull; the filter loops until it finds an
   even value, so only as many naturals as needed are produced. */
typedef struct {
    int next;
} Naturals;

static int pull(Naturals *s) {
    return s->next++;
}

static int pull_even(Naturals *s) {
    int v;
    do {
        v = pull(s);
    } while (v % 2 != 0);
    return v;
}

int main(void) {
    Naturals nats = {1};
    for (int i = 0; i < 3; i++) {
        printf("%d", pull_even(&nats));
        if (i < 2) printf(" ");
    }
    printf("\n");
    return 0;
}
