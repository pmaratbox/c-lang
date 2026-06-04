#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

static void point_repr(Point p, char *buf, size_t n) {
    snprintf(buf, n, "Point(x=%d, y=%d)", p.x, p.y);
}

int main(void) {
    Point p = { 1, 2 };
    char buf[64];
    point_repr(p, buf, sizeof(buf));
    printf("%s\n", buf);
    return 0;
}
