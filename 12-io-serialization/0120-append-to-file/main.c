#include <stdio.h>
#include <string.h>

int main(void) {
    const char *path = "append.tmp";

    FILE *w = fopen(path, "w");
    fprintf(w, "a\n");
    fclose(w);

    FILE *a = fopen(path, "a");
    fprintf(a, "b\n");
    fclose(a);

    FILE *r = fopen(path, "r");
    char buf[256];
    char out[256];
    out[0] = '\0';
    int first = 1;
    while (fgets(buf, sizeof buf, r)) {
        buf[strcspn(buf, "\n")] = '\0';
        if (!first) strcat(out, " ");
        strcat(out, buf);
        first = 0;
    }
    fclose(r);
    remove(path);

    printf("%s\n", out);
    return 0;
}
