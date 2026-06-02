#include <stdio.h>
#include <string.h>

int main(void) {
    const char *words[] = {"one", "two", "three"};
    int count = (int)(sizeof(words) / sizeof(words[0]));

    int maxlen = 0;
    for (int i = 0; i < count; i++) {
        int len = (int)strlen(words[i]);
        if (len > maxlen) maxlen = len;
    }

    int first_group = 1;
    for (int len = 1; len <= maxlen; len++) {
        int any = 0;
        for (int i = 0; i < count; i++) {
            if ((int)strlen(words[i]) == len) { any = 1; break; }
        }
        if (!any) continue;

        if (!first_group) printf(" ");
        printf("%d:[", len);
        int first_word = 1;
        for (int i = 0; i < count; i++) {
            if ((int)strlen(words[i]) == len) {
                if (!first_word) printf(",");
                printf("%s", words[i]);
                first_word = 0;
            }
        }
        printf("]");
        first_group = 0;
    }
    printf("\n");
    return 0;
}
