#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *k;
    int v;
} Entry;

static int cmp(const void *a, const void *b) {
    return ((const Entry *)a)->v - ((const Entry *)b)->v;
}

int main(void) {
    Entry entries[] = {{"a", 3}, {"b", 1}, {"c", 2}};
    qsort(entries, 3, sizeof(Entry), cmp);
    for (int i = 0; i < 3; i++) {
        if (i > 0) printf(" ");
        printf("%s:%d", entries[i].k, entries[i].v);
    }
    printf("\n");
    return 0;
}
