#include <stdio.h>

#define N 5
static int bit[N + 1]; /* 1-indexed */

static void update(int i, int delta) {
    for (; i <= N; i += i & (-i)) bit[i] += delta;
}

static int prefix(int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i)) sum += bit[i];
    return sum;
}

int main(void) {
    int data[N] = {1, 2, 3, 4, 5};
    for (int i = 0; i < N; i++) update(i + 1, data[i]);
    printf("%d\n", prefix(4));
    return 0;
}
