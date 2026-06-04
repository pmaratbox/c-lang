#include <stdio.h>

#define N 4

static int parent[N];

static int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];   /* path compression */
        x = parent[x];
    }
    return x;
}

static void unite(int a, int b) { parent[find(a)] = find(b); }

static int connected(int a, int b) { return find(a) == find(b); }

int main(void) {
    for (int i = 0; i < N; i++) parent[i] = i;
    unite(0, 1);
    unite(2, 3);
    printf("%s %s\n", connected(0, 1) ? "yes" : "no",
                      connected(0, 2) ? "yes" : "no");
    return 0;
}
