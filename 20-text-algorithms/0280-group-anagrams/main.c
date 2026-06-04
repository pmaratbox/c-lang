#include <stdio.h>
#include <string.h>

static void sort_key(const char *w, char *out) {
    int n = (int)strlen(w);
    for (int i = 0; i < n; i++) out[i] = w[i];
    out[n] = '\0';
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (out[j] < out[i]) {
                char t = out[i];
                out[i] = out[j];
                out[j] = t;
            }
        }
    }
}

int main(void) {
    const char *words[] = {"eat", "tea", "tan", "ate", "nat"};
    int count = 5;

    char keys[5][16];
    int groups = 0;
    for (int i = 0; i < count; i++) {
        char key[16];
        sort_key(words[i], key);
        int seen = 0;
        for (int j = 0; j < groups; j++) {
            if (strcmp(keys[j], key) == 0) { seen = 1; break; }
        }
        if (!seen) {
            strcpy(keys[groups++], key);
        }
    }
    printf("%d\n", groups);
    return 0;
}
