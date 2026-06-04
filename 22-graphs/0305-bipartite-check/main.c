#include <stdio.h>
#include <stdbool.h>

bool bipartite(int n, bool adj[][4]) {
    int color[4];
    for (int i = 0; i < n; i++) color[i] = -1;

    for (int s = 0; s < n; s++) {
        if (color[s] != -1) continue;
        int queue[4], head = 0, tail = 0;
        color[s] = 0;
        queue[tail++] = s;
        while (head < tail) {
            int u = queue[head++];
            for (int v = 0; v < n; v++) {
                if (!adj[u][v]) continue;
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    queue[tail++] = v;
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main(void) {
    bool cycle4[4][4] = { { false } };
    cycle4[0][1] = cycle4[1][0] = true;
    cycle4[1][2] = cycle4[2][1] = true;
    cycle4[2][3] = cycle4[3][2] = true;
    cycle4[3][0] = cycle4[0][3] = true;

    bool tri[4][4] = { { false } };
    tri[0][1] = tri[1][0] = true;
    tri[1][2] = tri[2][1] = true;
    tri[2][0] = tri[0][2] = true;

    printf("%s %s\n",
           bipartite(4, cycle4) ? "yes" : "no",
           bipartite(3, tri) ? "yes" : "no");
    return 0;
}
