#include <stdio.h>
#include <pthread.h>

void *task(void *arg) {
    return arg;
}

int main(void) {
    int x1 = 1, x2 = 2;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, task, &x1);
    pthread_create(&t2, NULL, task, &x2);
    void *r1, *r2;
    pthread_join(t1, &r1);
    pthread_join(t2, &r2);
    printf("sum: %d\n", *(int *)r1 + *(int *)r2);
    return 0;
}
