#include <stdio.h>

int main(void) {
    int stack[8];
    int top = 0;
    for (int n = 1; n <= 3; n++) {
        stack[top++] = n;
    }

    printf("%d", stack[--top]);
    while (top > 0) {
        printf(" %d", stack[--top]);
    }
    printf("\n");
    return 0;
}
