#include <stdio.h>
#include <string.h>

int main(void) {
    char s[] = "hello world";
    char *words[64];
    int n = 0;
    char *tok = strtok(s, " ");
    while (tok) {
        words[n++] = tok;
        tok = strtok(NULL, " ");
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%s%s", words[i], i > 0 ? " " : "");
    }
    printf("\n");
    return 0;
}
