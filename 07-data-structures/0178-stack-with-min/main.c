#include <stdio.h>

#define CAP 16

static int data[CAP];
static int mins[CAP];
static int size = 0;

static void push(int v) {
    data[size] = v;
    mins[size] = (size == 0 || v < mins[size - 1]) ? v : mins[size - 1];
    size++;
}

static int get_min(void) { return mins[size - 1]; }

int main(void) {
    push(3);
    push(1);
    push(2);
    printf("min: %d\n", get_min());
    return 0;
}
