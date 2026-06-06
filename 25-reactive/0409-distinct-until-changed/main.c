#include <stdio.h>
#include <stdbool.h>

/* A push-based Observable implemented from scratch: an observer is a callback
   plus state; subscribe drives the producer. distinctUntilChanged forwards a
   value only when it differs from the last forwarded value. */

typedef struct {
    bool has_last;
    int last;
} DistinctState;

static void emit(DistinctState *s, int value) {
    if (!s->has_last || value != s->last) {
        s->has_last = true;
        s->last = value;
        printf("%d\n", value);
    }
}

int main(void) {
    int source[] = {1, 1, 2, 2, 2, 3, 1};
    int n = (int)(sizeof(source) / sizeof(source[0]));

    DistinctState state = {false, 0};
    for (int i = 0; i < n; i++) {
        emit(&state, source[i]);
    }

    return 0;
}
