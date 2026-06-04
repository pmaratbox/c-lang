#include <stdio.h>
#include <stdbool.h>

#define N 4

int main(void) {
    bool adj[N][N] = { { false } };
    adj[0][1] = adj[0][2] = adj[1][3] = adj[2][3] = true;

    int indeg[N] = { 0 };
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (adj[i][j]) indeg[j]++;

    bool used[N] = { false };
    for (int out = 0; out < N; out++) {
        int pick = -1;
        for (int i = 0; i < N; i++)
            if (!used[i] && indeg[i] == 0) { pick = i; break; }
        used[pick] = true;
        for (int j = 0; j < N; j++)
            if (adj[pick][j]) indeg[j]--;
        printf("%d%s", pick, out + 1 < N ? " " : "\n");
    }
    return 0;
}
