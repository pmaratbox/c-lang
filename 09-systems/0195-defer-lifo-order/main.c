#include <stdio.h>

int main(void) {
    int stack[3]; /* emulate defer with an explicit LIFO stack */
    int top = 0;
    stack[top++] = 1;
    stack[top++] = 2;
    stack[top++] = 3;

    while (top > 0) {
        printf("%d", stack[--top]);
        if (top > 0) printf(" ");
    }
    printf("\n");
    return 0;
}
