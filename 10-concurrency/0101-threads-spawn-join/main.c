#include <stdio.h>
#include <pthread.h>

static void *worker(void *arg) {
    (void)arg;
    return NULL;
}

int main(void) {
    pthread_t threads[3];
    int joined = 0;
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
        joined++;
    }
    printf("done: %d\n", joined);
    return 0;
}
