#include <stdio.h>
#include <pthread.h>

static void *square(void *arg) {
    int n = *(int *)arg;
    int *result = arg;
    *result = n * n;
    return result;
}

int main(void) {
    int a = 3, b = 4;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, square, &a);
    pthread_create(&t2, NULL, square, &b);
    void *r1, *r2;
    pthread_join(t1, &r1);
    pthread_join(t2, &r2);
    int sum = *(int *)r1 + *(int *)r2;
    printf("%d\n", sum);
    return 0;
}
