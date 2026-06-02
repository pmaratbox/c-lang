#include <stdio.h>
#include <string.h>

int main(void) {
    const char *text = "aaabbc";
    int n = (int)strlen(text);
    int i = 0;
    while (i < n) {
        char ch = text[i];
        int count = 0;
        while (i < n && text[i] == ch) {
            count++;
            i++;
        }
        printf("%c%d", ch, count);
    }
    printf("\n");
    return 0;
}
