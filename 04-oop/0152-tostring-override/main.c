#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

static void point_to_string(const Point *p, char *buf, int n) {
    snprintf(buf, n, "Point(%d, %d)", p->x, p->y);
}

int main(void) {
    Point p = { .x = 1, .y = 2 };
    char buf[32];
    point_to_string(&p, buf, sizeof(buf));
    printf("%s\n", buf);
    return 0;
}
