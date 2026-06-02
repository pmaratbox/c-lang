#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

static int anagram(const char *a, const char *b) {
    char x[64], y[64];
    if (strlen(a) != strlen(b)) return 0;
    strcpy(x, a);
    strcpy(y, b);
    qsort(x, strlen(x), 1, cmp);
    qsort(y, strlen(y), 1, cmp);
    return strcmp(x, y) == 0;
}

int main(void) {
    const char *pairs[][2] = {{"listen", "silent"}, {"hello", "world"}};
    for (int i = 0; i < 2; i++) {
        printf("%s/%s: %s\n", pairs[i][0], pairs[i][1], anagram(pairs[i][0], pairs[i][1]) ? "yes" : "no");
    }
    return 0;
}
