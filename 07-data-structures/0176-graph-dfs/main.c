#include <stdio.h>

#define N 4

static int adj[N][N] = {
    {1, 2},
    {0, 3},
    {0, 3},
    {1, 2},
};
static int deg[N] = {2, 2, 2, 2};
static int visited[N];
static int first = 1;

static void dfs(int u) {
    visited[u] = 1;
    printf("%s%d", first ? "" : " ", u);
    first = 0;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) dfs(v);
    }
}

int main(void) {
    dfs(0);
    printf("\n");
    return 0;
}
