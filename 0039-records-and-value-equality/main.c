#include <stdio.h>

struct Point {
    int x, y;
};

int main(void) {
    struct Point p1 = {1, 2};
    struct Point p2 = {1, 2};
    printf("point: (%d, %d)\n", p1.x, p1.y);
    int equal = (p1.x == p2.x && p1.y == p2.y);
    printf("equal: %s\n", equal ? "yes" : "no");
    return 0;
}
