#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

int main(void) {
    int w[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            w[i][j] = -1;
    w[0][1] = 4; w[0][2] = 1; w[2][1] = 2; w[1][3] = 1; w[2][3] = 5;

    int dist[N], prev[N];
    bool done[N] = { false };
    for (int i = 0; i < N; i++) { dist[i] = INT_MAX; prev[i] = -1; }
    dist[0] = 0;

    for (int it = 0; it < N; it++) {
        int u = -1, best = INT_MAX;
        for (int i = 0; i < N; i++)
            if (!done[i] && dist[i] < best) { best = dist[i]; u = i; }
        if (u == -1) break;
        done[u] = true;
        for (int v = 0; v < N; v++)
            if (w[u][v] >= 0 && dist[u] != INT_MAX && dist[u] + w[u][v] < dist[v]) {
                dist[v] = dist[u] + w[u][v];
                prev[v] = u;
            }
    }

    int path[N], len = 0;
    for (int at = N - 1; at != -1; at = prev[at]) path[len++] = at;
    for (int i = len - 1; i >= 0; i--)
        printf("%d%s", path[i], i > 0 ? " " : "\n");
    return 0;
}
