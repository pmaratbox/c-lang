#include <stdio.h>

int main(void) {
    const char *path = "greeting.txt";

    FILE *out = fopen(path, "w");
    fputs("hello, file", out);
    fclose(out);

    char buf[64];
    FILE *in = fopen(path, "r");
    size_t n = fread(buf, 1, sizeof(buf) - 1, in);
    buf[n] = '\0';
    fclose(in);

    remove(path);
    printf("read: %s\n", buf);
    return 0;
}
