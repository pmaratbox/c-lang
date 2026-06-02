#include <stdio.h>

int main(void) {
    int queue[3];
    int head = 0, tail = 0;

    queue[tail++] = 1;
    queue[tail++] = 2;
    queue[tail++] = 3;

    while (head < tail) {
        printf("%d", queue[head]);
        head++;
        if (head < tail) printf(" ");
    }
    printf("\n");
    return 0;
}
