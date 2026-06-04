#include <stdio.h>
#include <ctype.h>

static int prec(char op) {
    return (op == '*') ? 2 : 1;
}

int main(void) {
    const char *s = "3 + 4 * 2";
    char ops[64];
    int top = 0;
    int first = 1;

    for (const char *p = s; *p; p++) {
        if (isdigit((unsigned char)*p)) {
            if (!first) printf(" ");
            printf("%c", *p);
            first = 0;
        } else if (*p == '+' || *p == '*') {
            while (top > 0 && prec(ops[top - 1]) >= prec(*p)) {
                printf(" %c", ops[--top]);
            }
            ops[top++] = *p;
        }
    }
    while (top > 0) {
        printf(" %c", ops[--top]);
    }
    printf("\n");
    return 0;
}
