#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *g_text;

static int cmp(const void *pa, const void *pb) {
    int a = *(const int *)pa;
    int b = *(const int *)pb;
    return strcmp(g_text + a, g_text + b);
}

int main(void) {
    const char *text = "banana";
    int n = (int)strlen(text);
    g_text = text;

    int sa[64];
    for (int i = 0; i < n; i++) sa[i] = i;
    qsort(sa, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", sa[i]);
    }
    printf("\n");
    return 0;
}
