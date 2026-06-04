#include <stdio.h>
#include <string.h>

int main(void) {
    const char *pattern = "ab";
    const char *text = "aab";
    int plen = (int)strlen(pattern);
    int state = 0; /* number of pattern chars matched so far */
    int result = -1;
    for (int i = 0; text[i]; i++) {
        if (text[i] == pattern[state]) {
            state++;
        } else {
            state = (text[i] == pattern[0]) ? 1 : 0;
        }
        if (state == plen) {
            result = i - plen + 1;
            break;
        }
    }
    printf("%d\n", result);
    return 0;
}
