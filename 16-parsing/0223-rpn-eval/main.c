#include <stdio.h>
#include <ctype.h>

int main(void) {
    const char *s = "3 4 + 5 *";
    int stack[64];
    int top = 0;
    for (const char *p = s; *p; p++) {
        if (isdigit((unsigned char)*p)) {
            stack[top++] = *p - '0';
        } else if (*p == '+' || *p == '*') {
            int b = stack[--top];
            int a = stack[--top];
            stack[top++] = (*p == '+') ? a + b : a * b;
        }
    }
    printf("%d\n", stack[top - 1]);
    return 0;
}
