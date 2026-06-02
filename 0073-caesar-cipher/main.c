#include <stdio.h>
#include <string.h>

int main(void) {
    char text[] = "abc";
    int shift = 1;
    for (size_t i = 0; i < strlen(text); i++) {
        text[i] = (char)((text[i] - 'a' + shift) % 26 + 'a');
    }
    printf("%s\n", text);
    return 0;
}
