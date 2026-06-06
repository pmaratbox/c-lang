#include <stdio.h>

/* A tiny push-based Observable, implemented from scratch.
 * An observer is a callback that receives "next" values.
 * zip buffers each source in a per-source queue; whenever both
 * queues are non-empty it dequeues one from each and emits a+b. */

typedef void (*observer_fn)(int value, void *state);

/* zip state: a per-source ring of buffered values */
typedef struct {
    int a_buf[8];
    int a_len;
    int b_buf[8];
    int b_len;
    observer_fn out;
    void *out_state;
} zip_state;

static void zip_drain(zip_state *z) {
    int i = 0;
    int n = z->a_len < z->b_len ? z->a_len : z->b_len;
    while (i < n) {
        z->out(z->a_buf[i] + z->b_buf[i], z->out_state);
        i++;
    }
    /* shift consumed elements out of both queues */
    int k;
    for (k = n; k < z->a_len; k++) z->a_buf[k - n] = z->a_buf[k];
    for (k = n; k < z->b_len; k++) z->b_buf[k - n] = z->b_buf[k];
    z->a_len -= n;
    z->b_len -= n;
}

static void zip_on_a(int value, void *state) {
    zip_state *z = (zip_state *)state;
    z->a_buf[z->a_len++] = value;
    zip_drain(z);
}

static void zip_on_b(int value, void *state) {
    zip_state *z = (zip_state *)state;
    z->b_buf[z->b_len++] = value;
    zip_drain(z);
}

static void print_next(int value, void *state) {
    (void)state;
    printf("%d\n", value);
}

int main(void) {
    zip_state z = {{0}, 0, {0}, 0, print_next, NULL};

    /* sources a (1,2,3) and b (10,20,30) emit interleaved a,b,a,b,... */
    int a[3] = {1, 2, 3};
    int b[3] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        zip_on_a(a[i], &z);
        zip_on_b(b[i], &z);
    }

    return 0;
}
