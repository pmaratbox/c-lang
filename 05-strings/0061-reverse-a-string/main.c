#include <stdio.h>
#include <string.h>

int main(void) {
    char text[] = "abc";
    int n = (int)strlen(text);
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        char tmp = text[i];
        text[i] = text[j];
        text[j] = tmp;
    }
    printf("%s\n", text);
    return 0;
}
