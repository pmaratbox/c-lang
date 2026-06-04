#include <stdio.h>
#include <string.h>

int main(void) {
    const char *lines[] = {"[s]", "k=v"};
    int n = sizeof(lines) / sizeof(lines[0]);
    char section[64] = "";
    for (int i = 0; i < n; i++) {
        const char *line = lines[i];
        size_t len = strlen(line);
        if (line[0] == '[' && line[len - 1] == ']') {
            size_t inner = len - 2;
            memcpy(section, line + 1, inner);
            section[inner] = '\0';
        } else {
            const char *eq = strchr(line, '=');
            if (eq) {
                int klen = (int)(eq - line);
                printf("%s.%.*s=%s\n", section, klen, line, eq + 1);
            }
        }
    }
    return 0;
}
