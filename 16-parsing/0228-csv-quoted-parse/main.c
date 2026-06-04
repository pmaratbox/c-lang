#include <stdio.h>

int main(void) {
    const char *s = "a,\"b,c\",d";
    int in_quotes = 0;
    for (const char *p = s; *p; p++) {
        char c = *p;
        if (c == '"') {
            in_quotes = !in_quotes;
        } else if (c == ',' && !in_quotes) {
            printf("|");
        } else {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
