#include <stdio.h>

int main(void) {
    int m[2][2] = {{1, 2}, {3, 4}};
    int v[2] = {5, 6};
    int r0 = m[0][0] * v[0] + m[0][1] * v[1];
    int r1 = m[1][0] * v[0] + m[1][1] * v[1];
    printf("%d %d\n", r0, r1);
    return 0;
}
