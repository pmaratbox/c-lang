#include <stdio.h>

/* Transducers compose transformations independent of the output. Here
   map(+1) feeds filter(even), reducing in a single pass over the input. */
static int first = 1;

static void emit(int x) {
    if (!first) printf(" ");
    printf("%d", x);
    first = 0;
}

/* filtering(even) step: only forward even values to emit */
static void filter_even_step(int x) {
    if (x % 2 == 0) emit(x);
}

/* mapping(+1) step: transform then pass to the next step */
static void map_inc_step(int x) {
    filter_even_step(x + 1);
}

int main(void) {
    int xs[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) map_inc_step(xs[i]);
    printf("\n");
    return 0;
}
