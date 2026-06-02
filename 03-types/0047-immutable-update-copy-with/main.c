#include <stdio.h>

struct Point {
    int x, y;
};

int main(void) {
    struct Point p1 = {1, 2};
    struct Point p2 = p1;
    p2.x = 9;
    printf("original: (%d, %d)\n", p1.x, p1.y);
    printf("updated: (%d, %d)\n", p2.x, p2.y);
    return 0;
}
