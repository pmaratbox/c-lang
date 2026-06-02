#include <stdio.h>

int main(void) {
    int i = 1;
    int first = 1;
    do {
        if (!first) printf(" ");
        printf("%d", i);
        first = 0;
        i++;
    } while (i <= 3);
    printf("\n");
    return 0;
}
