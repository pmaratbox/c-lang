#include <stdio.h>
#include <string.h>

int main(void) {
    const char *path = "lines.tmp";

    FILE *w = fopen(path, "w");
    fprintf(w, "alpha\nbeta\ngamma\n");
    fclose(w);

    FILE *r = fopen(path, "r");
    char buf[256];
    int count = 0;
    while (fgets(buf, sizeof buf, r)) {
        if (strspn(buf, " \t\r\n") != strlen(buf)) count++;
    }
    fclose(r);

    remove(path);

    printf("lines: %d\n", count);
    return 0;
}
