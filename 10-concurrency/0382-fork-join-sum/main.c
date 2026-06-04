#include <stdio.h>
#include <pthread.h>

typedef struct {
    int lo;
    int hi;
    int sum;
} range_t;

static void *sum_range(void *arg) {
    range_t *r = (range_t *)arg;
    if (r->hi - r->lo <= 1) {
        r->sum = r->lo;
        return NULL;
    }
    int mid = r->lo + (r->hi - r->lo) / 2;
    range_t left  = { r->lo, mid, 0 };
    range_t right = { mid, r->hi, 0 };
    pthread_t t;
    pthread_create(&t, NULL, sum_range, &left);
    sum_range(&right);
    pthread_join(t, NULL);
    r->sum = left.sum + right.sum;
    return NULL;
}

int main(void) {
    range_t all = { 1, 9, 0 };
    sum_range(&all);
    printf("%d\n", all.sum);
    return 0;
}
