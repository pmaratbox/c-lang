#include <stdio.h>
#include <string.h>

int main(void) {
    const char *tmpl = "hi {name}";
    const char *key = "name";
    const char *value = "Ada";

    for (const char *p = tmpl; *p; ) {
        if (*p == '{') {
            const char *end = strchr(p, '}');
            if (end) {
                size_t klen = (size_t)(end - p - 1);
                if (klen == strlen(key) && strncmp(p + 1, key, klen) == 0) {
                    printf("%s", value);
                }
                p = end + 1;
                continue;
            }
        }
        printf("%c", *p);
        p++;
    }
    printf("\n");
    return 0;
}
