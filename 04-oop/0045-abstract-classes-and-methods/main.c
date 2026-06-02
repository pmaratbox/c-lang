#include <stdio.h>

struct Shape {
    int side;
    int (*area)(struct Shape *self);
};

int square_area(struct Shape *self) {
    return self->side * self->side;
}

void describe(struct Shape *self) {
    printf("area: %d\n", self->area(self));
}

int main(void) {
    struct Shape sq = { .side = 3, .area = square_area };
    describe(&sq);
    return 0;
}
