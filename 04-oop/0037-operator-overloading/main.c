#include <stdio.h>

struct Point {
    int x, y;
};

struct Point add(struct Point a, struct Point b) {
    struct Point result = { a.x + b.x, a.y + b.y };
    return result;
}

int main(void) {
    struct Point p = add((struct Point){1, 2}, (struct Point){3, 4});
    printf("(%d, %d)\n", p.x, p.y);
    return 0;
}
