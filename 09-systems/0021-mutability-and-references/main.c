#include <stdio.h>

void inc(int *p) {
    (*p)++;
}

int main(void) {
    int n = 1;
    printf("before: %d\n", n);
    inc(&n);
    printf("after: %d\n", n);
    return 0;
}
