#include <stdio.h>
#include <stdbool.h>

#define N 3

int color[N]; /* 0 white, 1 gray, 2 black */
bool adj[N][N];

bool dfs(int u) {
    color[u] = 1;
    for (int v = 0; v < N; v++) {
        if (!adj[u][v]) continue;
        if (color[v] == 1) return true;
        if (color[v] == 0 && dfs(v)) return true;
    }
    color[u] = 2;
    return false;
}

int main(void) {
    adj[0][1] = adj[1][2] = adj[2][0] = true;

    bool found = false;
    for (int i = 0; i < N && !found; i++)
        if (color[i] == 0 && dfs(i)) found = true;

    printf("%s\n", found ? "cycle" : "acyclic");
    return 0;
}
