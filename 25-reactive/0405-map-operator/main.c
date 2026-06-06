#include <stdio.h>

/* A push-based Observable built from scratch: an observer is a callback,
   subscribe wires a producer to it. map() returns a new Observable whose
   next forwards f(value) to the downstream observer. */

typedef void (*next_fn)(int value);

typedef int (*map_fn)(int value);

/* The downstream sink for this lesson: just print the value. */
static void print_next(int value) {
    printf("%d\n", value);
}

/* The map operator: holds a transform and a downstream sink. Because C has
   no closures, we thread the mapping function through file-scope state. */
static map_fn current_map;
static next_fn current_sink;

static void mapped_next(int value) {
    current_sink(current_map(value));
}

static int times_two(int value) {
    return value * 2;
}

/* The source emits 1,2,3,4 by pushing each value into the given observer. */
static void source_subscribe(next_fn observer) {
    int values[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        observer(values[i]);
    }
}

int main(void) {
    current_map = times_two;
    current_sink = print_next;
    source_subscribe(mapped_next);
    return 0;
}
