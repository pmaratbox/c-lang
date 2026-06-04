#include <stdio.h>
#include <string.h>

int main(void) {
    const char *dir = "/tmp";
    const char *file = "file.txt";

    char joined[256];
    snprintf(joined, sizeof joined, "%s/%s", dir, file);

    const char *slash = strrchr(joined, '/');
    const char *base = slash ? slash + 1 : joined;

    const char *dot = strrchr(base, '.');
    const char *ext = dot ? dot : "";

    printf("%s %s %s\n", joined, base, ext);
    return 0;
}
