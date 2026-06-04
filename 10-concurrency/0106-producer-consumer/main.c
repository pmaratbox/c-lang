#include <stdio.h>
#include <pthread.h>

#define CAP 4

typedef struct {
    int buf[CAP];
    int count;
    int head;
    int closed;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} queue;

static queue q;

static void q_init(queue *q) {
    q->count = 0;
    q->head = 0;
    q->closed = 0;
    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->not_empty, NULL);
    pthread_cond_init(&q->not_full, NULL);
}

static void *producer(void *arg) {
    (void)arg;
    for (int i = 1; i <= 5; i++) {
        pthread_mutex_lock(&q.lock);
        while (q.count == CAP) {
            pthread_cond_wait(&q.not_full, &q.lock);
        }
        q.buf[(q.head + q.count) % CAP] = i;
        q.count++;
        pthread_cond_signal(&q.not_empty);
        pthread_mutex_unlock(&q.lock);
    }
    pthread_mutex_lock(&q.lock);
    q.closed = 1;
    pthread_cond_broadcast(&q.not_empty);
    pthread_mutex_unlock(&q.lock);
    return NULL;
}

int main(void) {
    q_init(&q);
    pthread_t prod;
    pthread_create(&prod, NULL, producer, NULL);

    int sum = 0;
    for (;;) {
        pthread_mutex_lock(&q.lock);
        while (q.count == 0 && !q.closed) {
            pthread_cond_wait(&q.not_empty, &q.lock);
        }
        if (q.count == 0 && q.closed) {
            pthread_mutex_unlock(&q.lock);
            break;
        }
        int v = q.buf[q.head];
        q.head = (q.head + 1) % CAP;
        q.count--;
        pthread_cond_signal(&q.not_full);
        pthread_mutex_unlock(&q.lock);
        sum += v;
    }
    pthread_join(prod, NULL);
    printf("%d\n", sum);
    return 0;
}
