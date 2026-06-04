#include <stdio.h>

#define N 3

static int neighbors(int g[N][N], int r, int c) {
    int count = 0;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < N && nc >= 0 && nc < N)
                count += g[nr][nc];
        }
    return count;
}

int main(void) {
    int g[N][N] = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 1, 0},
    };
    int next[N][N];
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            int n = neighbors(g, r, c);
            next[r][c] = (g[r][c] && (n == 2 || n == 3)) || (!g[r][c] && n == 3);
        }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            putchar(next[r][c] ? '#' : '.');
        putchar('\n');
    }
    return 0;
}
