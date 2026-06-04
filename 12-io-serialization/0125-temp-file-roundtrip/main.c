#include <stdio.h>
#include <string.h>

int main(void) {
    const char *path = "roundtrip.tmp";
    const char *data = "ok-data";

    FILE *w = fopen(path, "w");
    fputs(data, w);
    fclose(w);

    char buf[64];
    FILE *r = fopen(path, "r");
    size_t n = fread(buf, 1, sizeof buf - 1, r);
    buf[n] = '\0';
    fclose(r);

    remove(path);

    if (strcmp(buf, data) == 0) {
        printf("roundtrip: ok\n");
    } else {
        printf("roundtrip: mismatch\n");
    }
    return 0;
}
