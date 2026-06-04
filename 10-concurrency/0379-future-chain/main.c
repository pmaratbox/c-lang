#include <stdio.h>
#include <pthread.h>

typedef struct {
    int (*fn)(int);
    int in;
    int out;
} step_t;

static int times2(int x) { return x * 2; }
static int plus1(int x)  { return x + 1; }

static void *run_step(void *arg) {
    step_t *s = (step_t *)arg;
    s->out = s->fn(s->in);
    return NULL;
}

static int run(int (*fn)(int), int in) {
    pthread_t t;
    step_t s = { fn, in, 0 };
    pthread_create(&t, NULL, run_step, &s);
    pthread_join(t, NULL);
    return s.out;
}

int main(void) {
    int v = 5;
    v = run(times2, v);
    v = run(plus1, v);
    printf("%d\n", v);
    return 0;
}
