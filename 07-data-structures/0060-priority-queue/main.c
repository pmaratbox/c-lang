#include <stdio.h>

static int pq[16];
static int size = 0;

static void push(int n) {
    int i = size;
    while (i > 0 && pq[i - 1] > n) {
        pq[i] = pq[i - 1];
        i--;
    }
    pq[i] = n;
    size++;
}

static int pop(void) {
    int top = pq[0];
    for (int i = 1; i < size; i++) pq[i - 1] = pq[i];
    size--;
    return top;
}

int main(void) {
    int items[] = {3, 1, 2};
    for (int i = 0; i < 3; i++) push(items[i]);

    int first = 1;
    while (size > 0) {
        if (!first) printf(" ");
        printf("%d", pop());
        first = 0;
    }
    printf("\n");
    return 0;
}
