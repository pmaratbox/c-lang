#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char text[] = "hello world";
    int start = 1;
    for (size_t i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            start = 1;
        } else if (start) {
            text[i] = (char)toupper((unsigned char)text[i]);
            start = 0;
        }
    }
    printf("%s\n", text);
    return 0;
}
