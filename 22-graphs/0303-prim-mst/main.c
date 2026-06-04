#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4
#define INF INT_MAX

int main(void) {
    int w[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            w[i][j] = INF;
    w[0][1] = w[1][0] = 1;
    w[1][2] = w[2][1] = 2;
    w[2][3] = w[3][2] = 3;

    int key[N];
    bool in[N] = { false };
    for (int i = 0; i < N; i++) key[i] = INF;
    key[0] = 0;

    int total = 0;
    for (int it = 0; it < N; it++) {
        int u = -1, best = INF;
        for (int i = 0; i < N; i++)
            if (!in[i] && key[i] < best) { best = key[i]; u = i; }
        in[u] = true;
        total += key[u];
        for (int v = 0; v < N; v++)
            if (!in[v] && w[u][v] != INF && w[u][v] < key[v])
                key[v] = w[u][v];
    }

    printf("%d\n", total);
    return 0;
}
