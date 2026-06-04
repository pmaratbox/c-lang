#include <stdio.h>
#include <pthread.h>

#define CAP 8

typedef struct {
    int buf[CAP];
    int count;
    int head;
    int closed;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} channel;

static void chan_init(channel *c) {
    c->count = 0;
    c->head = 0;
    c->closed = 0;
    pthread_mutex_init(&c->lock, NULL);
    pthread_cond_init(&c->cond, NULL);
}

static void chan_send(channel *c, int v) {
    pthread_mutex_lock(&c->lock);
    c->buf[(c->head + c->count) % CAP] = v;
    c->count++;
    pthread_cond_signal(&c->cond);
    pthread_mutex_unlock(&c->lock);
}

static void chan_close(channel *c) {
    pthread_mutex_lock(&c->lock);
    c->closed = 1;
    pthread_cond_broadcast(&c->cond);
    pthread_mutex_unlock(&c->lock);
}

static int chan_recv(channel *c, int *out) {
    pthread_mutex_lock(&c->lock);
    while (c->count == 0 && !c->closed) {
        pthread_cond_wait(&c->cond, &c->lock);
    }
    if (c->count == 0 && c->closed) {
        pthread_mutex_unlock(&c->lock);
        return 0;
    }
    *out = c->buf[c->head];
    c->head = (c->head + 1) % CAP;
    c->count--;
    pthread_mutex_unlock(&c->lock);
    return 1;
}

static void *producer(void *arg) {
    channel *c = arg;
    for (int i = 1; i <= 3; i++) {
        chan_send(c, i);
    }
    chan_close(c);
    return NULL;
}

int main(void) {
    channel c;
    chan_init(&c);
    pthread_t t;
    pthread_create(&t, NULL, producer, &c);

    int v;
    int first = 1;
    while (chan_recv(&c, &v)) {
        if (!first) printf(" ");
        printf("%d", v);
        first = 0;
    }
    printf("\n");
    pthread_join(t, NULL);
    return 0;
}
