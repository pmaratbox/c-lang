#include <stdio.h>
#include <stddef.h>

typedef struct Shape {
    const char *(*name)(const struct Shape *self);
    int (*area)(const struct Shape *self);
    int a, b;
} Shape;

static const char *rect_name(const Shape *self) { (void)self; return "rectangle"; }
static int rect_area(const Shape *self) { return self->a * self->b; }

static const char *square_name(const Shape *self) { (void)self; return "square"; }
static int square_area(const Shape *self) { return self->a * self->a; }

int main(void) {
    Shape shapes[] = {
        { rect_name, rect_area, 3, 4 },
        { square_name, square_area, 5, 0 },
    };
    size_t n = sizeof(shapes) / sizeof(shapes[0]);
    for (size_t i = 0; i < n; i++) {
        const Shape *s = &shapes[i];
        printf("%s area: %d\n", s->name(s), s->area(s));
    }
    return 0;
}
