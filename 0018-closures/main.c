#include <stdio.h>

typedef struct {
    int count;
} Counter;

int next(Counter *c) {
    c->count += 1;
    return c->count;
}

int main(void) {
    Counter c = {0};
    printf("count: %d\n", next(&c));
    printf("count: %d\n", next(&c));
    return 0;
}
