#include <stdio.h>

typedef struct {
    const char *k;
    int v;
} Entry;

int main(void) {
    Entry m[] = {{"a", 1}, {"b", 2}, {"c", 3}};
    int first = 1;
    for (int v = 1; v <= 3; v++) {
        for (int i = 0; i < 3; i++) {
            if (m[i].v == v) {
                if (!first) printf(" ");
                printf("%d:%s", v, m[i].k);
                first = 0;
            }
        }
    }
    printf("\n");
    return 0;
}
