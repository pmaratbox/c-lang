#include <stdio.h>
#include <string.h>

int main(void) {
    const char *word = "hello";
    int count = 0;
    for (size_t i = 0; i < strlen(word); i++) {
        if (strchr("aeiou", word[i])) count++;
    }
    printf("%d\n", count);
    return 0;
}
