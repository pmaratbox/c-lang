#include <stdio.h>
#include <pthread.h>

#define N 3

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t all_here = PTHREAD_COND_INITIALIZER;
static int arrived = 0;

static void *worker(void *arg) {
    (void)arg;
    pthread_mutex_lock(&lock);
    arrived++;
    if (arrived == N) {
        pthread_cond_broadcast(&all_here);
    } else {
        while (arrived < N) {
            pthread_cond_wait(&all_here, &lock);
        }
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void) {
    pthread_t threads[N];
    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("all reached: %d\n", arrived);
    return 0;
}
