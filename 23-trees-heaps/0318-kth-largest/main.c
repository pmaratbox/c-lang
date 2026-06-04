#include <stdio.h>

/* Size-k min-heap holding the k largest seen so far. */
static int heap[8];
static int n;
static int cap;

static void swap(int i, int j) { int t = heap[i]; heap[i] = heap[j]; heap[j] = t; }

static void sift_up(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= heap[i]) break;
        swap(p, i);
        i = p;
    }
}

static void sift_down(int i) {
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, small = i;
        if (l < n && heap[l] < heap[small]) small = l;
        if (r < n && heap[r] < heap[small]) small = r;
        if (small == i) break;
        swap(i, small);
        i = small;
    }
}

static void offer(int v) {
    if (n < cap) {
        heap[n++] = v;
        sift_up(n - 1);
    } else if (v > heap[0]) {
        heap[0] = v;
        sift_down(0);
    }
}

int main(void) {
    int vals[] = {3, 2, 1, 5, 6, 4};
    cap = 2;
    for (int i = 0; i < 6; i++) offer(vals[i]);
    printf("%d\n", heap[0]); /* root of size-2 min-heap = 2nd largest */
    return 0;
}
