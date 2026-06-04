#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

static atomic_int counter = 0;

static void *increment(void *arg) {
    (void)arg;
    for (int i = 0; i < 100; i++) {
        atomic_fetch_add(&counter, 1);
    }
    return NULL;
}

int main(void) {
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("%d\n", atomic_load(&counter));
    return 0;
}
