#include <stdio.h>
#include <ctype.h>

static const char *cur;

static int factor(void) {
    int n = 0;
    while (isdigit((unsigned char)*cur)) {
        n = n * 10 + (*cur - '0');
        cur++;
    }
    return n;
}

static int term(void) {
    int v = factor();
    while (*cur == '*') {
        cur++;
        v *= factor();
    }
    return v;
}

static int expr(void) {
    int v = term();
    while (*cur == '+') {
        cur++;
        v += term();
    }
    return v;
}

int main(void) {
    cur = "2+3*4";
    printf("%d\n", expr());
    return 0;
}
