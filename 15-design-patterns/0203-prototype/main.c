#include <stdio.h>

typedef struct {
    int value;
} Prototype;

Prototype clone(const Prototype *p) {
    Prototype copy = *p;
    return copy;
}

int main(void) {
    Prototype original = {1};
    Prototype c = clone(&original);
    c.value = 2;
    printf("%d %d\n", original.value, c.value);
    return 0;
}
