#include <stdio.h>
#include <string.h>

int main(void) {
    const char *a = "123";
    const char *b = "456";
    int la = (int)strlen(a), lb = (int)strlen(b);
    int res[64] = {0};
    for (int i = la - 1; i >= 0; i--) {
        for (int j = lb - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int pos = (la - 1 - i) + (lb - 1 - j);
            res[pos] += mul;
            res[pos + 1] += res[pos] / 10;
            res[pos] %= 10;
        }
    }
    int top = 63;
    while (top > 0 && res[top] == 0) top--;
    for (int k = top; k >= 0; k--) putchar((char)('0' + res[k]));
    putchar('\n');
    return 0;
}
