#include <stdio.h>

#define CAP 16

static int heap[CAP];
static int size = 0;

static void swap(int i, int j) { int t = heap[i]; heap[i] = heap[j]; heap[j] = t; }

static void push(int v) {
    int i = size++;
    heap[i] = v;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i]) break;
        swap(parent, i);
        i = parent;
    }
}

static int pop(void) {
    int top = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    for (;;) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        swap(i, smallest);
        i = smallest;
    }
    return top;
}

int main(void) {
    push(3);
    push(1);
    push(2);
    int first = 1;
    while (size > 0) {
        printf("%s%d", first ? "" : " ", pop());
        first = 0;
    }
    printf("\n");
    return 0;
}
