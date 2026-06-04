#include <stdio.h>
#include <string.h>

int main(void) {
    const char *words[] = {"flower", "flow", "flight"};
    int n = 3;
    int i = 0;
    while (1) {
        char c = words[0][i];
        if (c == '\0') break;
        int mismatch = 0;
        for (int w = 1; w < n; w++) {
            if (words[w][i] != c) { mismatch = 1; break; }
        }
        if (mismatch) break;
        putchar(c);
        i++;
    }
    printf("\n");
    return 0;
}
