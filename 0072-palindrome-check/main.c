#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s) {
    int i = 0, j = (int)strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

int main(void) {
    const char *words[] = {"level", "hello"};
    for (int k = 0; k < 2; k++) {
        printf("%s: %s\n", words[k], is_palindrome(words[k]) ? "yes" : "no");
    }
    return 0;
}
