#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3
#define CELLS (SIZE * SIZE)

static int idx(int r, int c) { return r * SIZE + c; }
static int manhattan(int r, int c) { return abs(SIZE - 1 - r) + abs(SIZE - 1 - c); }

int main(void) {
    int g[CELLS];
    bool closed[CELLS] = { false };
    for (int i = 0; i < CELLS; i++) g[i] = INT_MAX;
    g[idx(0, 0)] = 0;

    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };
    int goal = idx(SIZE - 1, SIZE - 1);

    while (true) {
        int cur = -1, bestf = INT_MAX;
        for (int i = 0; i < CELLS; i++) {
            if (closed[i] || g[i] == INT_MAX) continue;
            int r = i / SIZE, c = i % SIZE;
            int f = g[i] + manhattan(r, c);
            if (f < bestf) { bestf = f; cur = i; }
        }
        if (cur == -1 || cur == goal) break;
        closed[cur] = true;
        int r = cur / SIZE, c = cur % SIZE;
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE) continue;
            int ni = idx(nr, nc);
            if (g[cur] + 1 < g[ni]) g[ni] = g[cur] + 1;
        }
    }

    printf("%d\n", g[goal]);
    return 0;
}
