#include <stdio.h>

#define N 4

int main(void) {
    /* undirected graph as adjacency list */
    int adj[N][N] = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2},
    };
    int deg[N] = {2, 2, 2, 2};

    for (int i = 0; i < deg[0]; i++)
        printf("%d%s", adj[0][i], i + 1 < deg[0] ? " " : "\n");
    return 0;
}
