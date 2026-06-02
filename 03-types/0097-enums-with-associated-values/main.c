#include <stdio.h>

typedef enum { RECT, SQUARE } ShapeKind;

typedef struct {
    ShapeKind kind;
    union {
        struct { int w, h; } rect;
        struct { int s; } square;
    } data;
} Shape;

static int area(Shape shape) {
    if (shape.kind == RECT) return shape.data.rect.w * shape.data.rect.h;
    return shape.data.square.s * shape.data.square.s;
}

int main(void) {
    Shape shapes[2];
    shapes[0].kind = RECT;
    shapes[0].data.rect.w = 2;
    shapes[0].data.rect.h = 3;
    shapes[1].kind = SQUARE;
    shapes[1].data.square.s = 4;
    for (int i = 0; i < 2; i++) {
        printf("%d\n", area(shapes[i]));
    }
    return 0;
}
