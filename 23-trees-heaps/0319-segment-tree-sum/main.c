#include <stdio.h>

#define N 5
static int tree[4 * N];
static int data[N] = {1, 2, 3, 4, 5};

static void build(int node, int lo, int hi) {
    if (lo == hi) { tree[node] = data[lo]; return; }
    int mid = (lo + hi) / 2;
    build(2 * node, lo, mid);
    build(2 * node + 1, mid + 1, hi);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

static int query(int node, int lo, int hi, int l, int r) {
    if (r < lo || hi < l) return 0;
    if (l <= lo && hi <= r) return tree[node];
    int mid = (lo + hi) / 2;
    return query(2 * node, lo, mid, l, r) +
           query(2 * node + 1, mid + 1, hi, l, r);
}

int main(void) {
    build(1, 0, N - 1);
    printf("%d\n", query(1, 0, N - 1, 1, 3));
    return 0;
}
