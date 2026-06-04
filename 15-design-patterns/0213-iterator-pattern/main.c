#include <stdio.h>

typedef struct {
    int current;
    int end;
} RangeIterator;

int has_next(const RangeIterator *it) {
    return it->current <= it->end;
}

int next(RangeIterator *it) {
    return it->current++;
}

int main(void) {
    RangeIterator it = {1, 3};
    int first = 1;
    while (has_next(&it)) {
        int v = next(&it);
        printf("%s%d", first ? "" : " ", v);
        first = 0;
    }
    printf("\n");
    return 0;
}
