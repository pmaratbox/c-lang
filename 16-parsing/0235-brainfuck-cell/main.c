#include <stdio.h>

int main(void) {
    const char *prog = "+++";
    int cell = 0;
    for (const char *p = prog; *p; p++) {
        if (*p == '+') cell++;
        else if (*p == '-') cell--;
    }
    printf("%d\n", cell);
    return 0;
}
