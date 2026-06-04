#include <stdio.h>

int main(void) {
    int m[2][2] = {{1, 2}, {3, 4}};
    int det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
    printf("%d\n", det);
    return 0;
}
