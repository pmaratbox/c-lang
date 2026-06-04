#include <stdio.h>
#include <string.h>

typedef struct {
    char size[8];
    char topping[16];
} PizzaBuilder;

typedef struct {
    char size[8];
    char topping[16];
} Pizza;

static PizzaBuilder *set_size(PizzaBuilder *b, const char *size) {
    strncpy(b->size, size, sizeof(b->size) - 1);
    return b;
}

static PizzaBuilder *add_topping(PizzaBuilder *b, const char *topping) {
    strncpy(b->topping, topping, sizeof(b->topping) - 1);
    return b;
}

static Pizza build(const PizzaBuilder *b) {
    Pizza p = {0};
    strncpy(p.size, b->size, sizeof(p.size) - 1);
    strncpy(p.topping, b->topping, sizeof(p.topping) - 1);
    return p;
}

int main(void) {
    PizzaBuilder b = {0};
    Pizza p = build(add_topping(set_size(&b, "M"), "cheese"));
    printf("Pizza(%s, %s)\n", p.size, p.topping);
    return 0;
}
