#include <stdio.h>

typedef struct { int x; int y; } Point;

static Point point_default(void) {
    Point p = { .x = 0, .y = 0 };
    return p;
}

int main(void) {
    Point a = point_default();
    Point b = point_default();
    b.x = 5;
    printf("%d %d\n", a.x, a.y);
    printf("%d %d\n", b.x, b.y);
    return 0;
}
