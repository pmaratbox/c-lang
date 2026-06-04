#include <stdio.h>

#define N 3
#define E 3

int parent[N];

int find(int x) {
    while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
    return x;
}

int main(void) {
    int u[E] = { 0, 1, 0 };
    int v[E] = { 1, 2, 2 };
    int w[E] = { 1, 2, 3 };

    /* selection sort edges by weight */
    for (int i = 0; i < E; i++)
        for (int j = i + 1; j < E; j++)
            if (w[j] < w[i]) {
                int t;
                t = w[i]; w[i] = w[j]; w[j] = t;
                t = u[i]; u[i] = u[j]; u[j] = t;
                t = v[i]; v[i] = v[j]; v[j] = t;
            }

    for (int i = 0; i < N; i++) parent[i] = i;

    int total = 0;
    for (int e = 0; e < E; e++) {
        int ru = find(u[e]), rv = find(v[e]);
        if (ru != rv) { parent[ru] = rv; total += w[e]; }
    }

    printf("%d\n", total);
    return 0;
}
