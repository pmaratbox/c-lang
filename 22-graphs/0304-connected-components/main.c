#include <stdio.h>

#define N 5

int parent[N];

int find(int x) {
    while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
    return x;
}

void uni(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra != rb) parent[ra] = rb;
}

int main(void) {
    for (int i = 0; i < N; i++) parent[i] = i;
    uni(0, 1); uni(1, 2); uni(3, 4);

    int count = 0;
    for (int i = 0; i < N; i++)
        if (find(i) == i) count++;

    printf("%d\n", count);
    return 0;
}
