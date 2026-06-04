#include <stdio.h>

typedef struct Shape {
    double (*area)(const struct Shape *self);
} Shape;

typedef struct {
    Shape base;
    double w;
    double h;
} Rectangle;

typedef struct {
    Shape base;
    double b;
    double h;
} Triangle;

static double rect_area(const Shape *self) {
    const Rectangle *r = (const Rectangle *)self;
    return r->w * r->h;
}

static double tri_area(const Shape *self) {
    const Triangle *t = (const Triangle *)self;
    return t->b * t->h / 2.0;
}

int main(void) {
    Rectangle r = { { rect_area }, 2, 3 };
    Triangle t = { { tri_area }, 4, 4 };
    Shape *shapes[] = { &r.base, &t.base };
    double total = 0;
    for (int i = 0; i < 2; i++) {
        total += shapes[i]->area(shapes[i]);
    }
    printf("total area: %g\n", total);
    return 0;
}
