#include <stdio.h>

#define CAP 16

static int buf[CAP];
static int front = 0; /* index of first element */
static int size = 0;

static void push_back(int x) {
    buf[(front + size) % CAP] = x;
    size++;
}

static void push_front(int x) {
    front = (front - 1 + CAP) % CAP;
    buf[front] = x;
    size++;
}

int main(void) {
    push_back(1);
    push_back(2);
    push_front(0);

    for (int i = 0; i < size; i++) {
        if (i) printf(" ");
        printf("%d", buf[(front + i) % CAP]);
    }
    printf("\n");
    return 0;
}
