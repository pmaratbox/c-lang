#include <stdio.h>

static int heap[16];
static int n;

static void swap(int i, int j) { int t = heap[i]; heap[i] = heap[j]; heap[j] = t; }

static void push(int v) {
    int i = n++;
    heap[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] >= heap[i]) break;
        swap(p, i);
        i = p;
    }
}

static int pop(void) {
    int top = heap[0];
    heap[0] = heap[--n];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, big = i;
        if (l < n && heap[l] > heap[big]) big = l;
        if (r < n && heap[r] > heap[big]) big = r;
        if (big == i) break;
        swap(i, big);
        i = big;
    }
    return top;
}

int main(void) {
    int vals[] = {3, 1, 4, 1, 5};
    for (int i = 0; i < 5; i++) push(vals[i]);
    printf("%d %d %d\n", pop(), pop(), pop());
    return 0;
}
