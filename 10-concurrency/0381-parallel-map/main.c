#include <stdio.h>
#include <pthread.h>

#define N 4

typedef struct {
    int in;
    int out;
} item_t;

static void *square(void *arg) {
    item_t *it = (item_t *)arg;
    it->out = it->in * it->in;
    return NULL;
}

int main(void) {
    item_t items[N] = { {1, 0}, {2, 0}, {3, 0}, {4, 0} };
    pthread_t t[N];
    for (int i = 0; i < N; i++) {
        pthread_create(&t[i], NULL, square, &items[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(t[i], NULL);
    }
    for (int i = 0; i < N; i++) {
        printf("%d%s", items[i].out, i + 1 < N ? " " : "\n");
    }
    return 0;
}
