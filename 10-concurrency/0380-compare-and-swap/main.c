#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

#define THREADS 4
#define PER 25

static atomic_int counter = 0;

static void *worker(void *arg) {
    (void)arg;
    for (int i = 0; i < PER; i++) {
        int cur = atomic_load(&counter);
        while (!atomic_compare_exchange_weak(&counter, &cur, cur + 1)) {
            /* cur reloaded by CAS; retry */
        }
    }
    return NULL;
}

int main(void) {
    pthread_t t[THREADS];
    for (int i = 0; i < THREADS; i++) {
        pthread_create(&t[i], NULL, worker, NULL);
    }
    for (int i = 0; i < THREADS; i++) {
        pthread_join(t[i], NULL);
    }
    printf("%d\n", atomic_load(&counter));
    return 0;
}
