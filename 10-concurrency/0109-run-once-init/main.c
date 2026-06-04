#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

static pthread_once_t once = PTHREAD_ONCE_INIT;
static atomic_int init_count = 0;

static void initialize(void) {
    atomic_fetch_add(&init_count, 1);
}

static void *racer(void *arg) {
    (void)arg;
    pthread_once(&once, initialize);
    return NULL;
}

int main(void) {
    pthread_t threads[8];
    for (int i = 0; i < 8; i++) {
        pthread_create(&threads[i], NULL, racer, NULL);
    }
    for (int i = 0; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("init count: %d\n", atomic_load(&init_count));
    return 0;
}
