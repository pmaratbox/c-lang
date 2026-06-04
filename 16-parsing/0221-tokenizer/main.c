#include <stdio.h>
#include <ctype.h>

int main(void) {
    const char *s = "1 + 2";
    int first = 1;
    for (const char *p = s; *p; p++) {
        const char *name = NULL;
        if (isdigit((unsigned char)*p)) name = "NUM";
        else if (*p == '+') name = "PLUS";
        if (name) {
            if (!first) printf(" ");
            printf("%s", name);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
