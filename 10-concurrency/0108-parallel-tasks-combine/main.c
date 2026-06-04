#include <stdio.h>
#include <pthread.h>

static void *task_a(void *arg) {
    int *out = arg;
    *out = 10;
    return NULL;
}

static void *task_b(void *arg) {
    int *out = arg;
    *out = 20;
    return NULL;
}

int main(void) {
    int a = 0, b = 0;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, task_a, &a);
    pthread_create(&t2, NULL, task_b, &b);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("%d\n", a + b);
    return 0;
}
