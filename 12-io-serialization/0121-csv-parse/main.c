#include <stdio.h>
#include <string.h>

int main(void) {
    const char *rows[] = {"alice,30", "bob,25"};
    size_t n = sizeof rows / sizeof rows[0];

    char out[256];
    out[0] = '\0';

    for (size_t i = 0; i < n; i++) {
        char line[64];
        strcpy(line, rows[i]);
        char *name = strtok(line, ",");
        char *value = strtok(NULL, ",");

        char pair[128];
        snprintf(pair, sizeof pair, "%s=%s", name, value);

        if (i > 0) strcat(out, " ");
        strcat(out, pair);
    }

    printf("%s\n", out);
    return 0;
}
