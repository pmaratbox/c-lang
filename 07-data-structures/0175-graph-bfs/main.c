#include <stdio.h>

#define N 4

int main(void) {
    int adj[N][N] = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2},
    };
    int deg[N] = {2, 2, 2, 2};

    int visited[N] = {0};
    int queue[N];
    int qh = 0, qt = 0;
    int first = 1;

    queue[qt++] = 0;
    visited[0] = 1;
    while (qh < qt) {
        int u = queue[qh++];
        printf("%s%d", first ? "" : " ", u);
        first = 0;
        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = 1;
                queue[qt++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}
