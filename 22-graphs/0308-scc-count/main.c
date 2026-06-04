#include <stdio.h>
#include <stdbool.h>

#define N 4

bool adj[N][N];
bool radj[N][N];
bool visited[N];
int order[N], oi;
int comp[N];

void dfs1(int u) {
    visited[u] = true;
    for (int v = 0; v < N; v++)
        if (adj[u][v] && !visited[v]) dfs1(v);
    order[oi++] = u;
}

void dfs2(int u, int c) {
    comp[u] = c;
    for (int v = 0; v < N; v++)
        if (radj[u][v] && comp[v] == -1) dfs2(v, c);
}

int main(void) {
    int from[] = { 0, 1, 2, 2 };
    int to[]   = { 1, 2, 0, 3 };
    for (int e = 0; e < 4; e++) {
        adj[from[e]][to[e]] = true;
        radj[to[e]][from[e]] = true;
    }

    for (int i = 0; i < N; i++)
        if (!visited[i]) dfs1(i);

    for (int i = 0; i < N; i++) comp[i] = -1;
    int count = 0;
    for (int i = oi - 1; i >= 0; i--) {
        int u = order[i];
        if (comp[u] == -1) dfs2(u, count++);
    }

    printf("%d\n", count);
    return 0;
}
