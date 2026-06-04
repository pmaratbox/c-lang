#include <stdio.h>

typedef struct Coffee {
    int (*cost)(const struct Coffee *self);
    const struct Coffee *inner;
} Coffee;

int base_cost(const Coffee *self) {
    (void)self;
    return 2;
}

int add_one(const Coffee *self) {
    return self->inner->cost(self->inner) + 1;
}

int main(void) {
    Coffee base = {base_cost, NULL};
    Coffee milk = {add_one, &base};
    Coffee sugar = {add_one, &milk};
    printf("%d\n", sugar.cost(&sugar));
    return 0;
}
