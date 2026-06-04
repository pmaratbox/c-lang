#include <stdio.h>

static int first = 1;

static void stop_at(int floor) {
    printf("%s%d", first ? "" : " ", floor);
    first = 0;
}

static void move_to(int *cur, int target) {
    while (*cur != target) {
        *cur += (target > *cur) ? 1 : -1;
        stop_at(*cur);
    }
}

int main(void) {
    int floor = 0;
    stop_at(floor);
    move_to(&floor, 2);
    move_to(&floor, 0);
    putchar('\n');
    return 0;
}
