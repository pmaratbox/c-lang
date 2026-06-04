#include <stdio.h>

#define CAP 3

static int buf[CAP];
static int head = 0;
static int tail = 0;
static int size = 0;

static int enqueue(int x) {
    if (size == CAP) return 0;
    buf[tail] = x;
    tail = (tail + 1) % CAP;
    size++;
    return 1;
}

static int dequeue(int *out) {
    if (size == 0) return 0;
    *out = buf[head];
    head = (head + 1) % CAP;
    size--;
    return 1;
}

int main(void) {
    int tmp;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue(&tmp);
    enqueue(4);

    for (int i = 0; i < size; i++) {
        if (i) printf(" ");
        printf("%d", buf[(head + i) % CAP]);
    }
    printf("\n");
    return 0;
}
