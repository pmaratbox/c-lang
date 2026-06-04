#include <stdio.h>
#include <limits.h>

#define N 3

int main(void) {
    int from[] = { 0, 1, 0 };
    int to[]   = { 1, 2, 2 };
    int wt[]   = { 1, -2, 4 };
    int E = 3;

    int dist[N];
    for (int i = 0; i < N; i++) dist[i] = INT_MAX;
    dist[0] = 0;

    for (int it = 0; it < N - 1; it++)
        for (int e = 0; e < E; e++)
            if (dist[from[e]] != INT_MAX && dist[from[e]] + wt[e] < dist[to[e]])
                dist[to[e]] = dist[from[e]] + wt[e];

    for (int i = 0; i < N; i++)
        printf("%d%s", dist[i], i + 1 < N ? " " : "\n");
    return 0;
}
