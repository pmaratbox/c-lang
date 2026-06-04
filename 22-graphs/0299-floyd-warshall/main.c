#include <stdio.h>

#define N 3
#define INF 1000000

int main(void) {
    int d[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            d[i][j] = (i == j) ? 0 : INF;
    d[0][1] = 3; d[1][2] = 1; d[0][2] = 5;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("%d\n", d[0][2]);
    return 0;
}
