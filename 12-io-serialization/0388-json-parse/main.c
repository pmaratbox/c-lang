#include <stdio.h>
#include <ctype.h>

int main(void) {
    const char *json = "{\"x\":1,\"y\":2}";
    const char *p = json;
    int first = 1;
    while (*p) {
        if (*p == '"') {
            const char *start = ++p;
            while (*p && *p != '"') p++;
            int klen = (int)(p - start);
            p++;                 /* closing quote */
            while (*p && *p != ':') p++;
            p++;                 /* colon */
            int val = 0;
            while (isdigit((unsigned char)*p)) {
                val = val * 10 + (*p - '0');
                p++;
            }
            if (!first) printf(" ");
            printf("%.*s=%d", klen, start, val);
            first = 0;
        } else {
            p++;
        }
    }
    printf("\n");
    return 0;
}
