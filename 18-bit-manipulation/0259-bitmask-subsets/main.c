#include <stdio.h>

int main(void) {
    int mask = 5;
    int sub = mask;
    int first = 1;
    while (1) {
        if (!first) printf(" ");
        printf("%d", sub);
        first = 0;
        if (sub == 0) break;
        sub = (sub - 1) & mask;
    }
    printf("\n");
    return 0;
}
