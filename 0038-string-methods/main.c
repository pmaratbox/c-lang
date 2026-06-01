#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char input[] = "a,b,c";
    char result[16] = "";
    char *token = strtok(input, ",");
    int first = 1;
    while (token != NULL) {
        if (!first) {
            strcat(result, "-");
        }
        first = 0;
        char up[8];
        size_t i = 0;
        for (; token[i] != '\0'; i++) {
            up[i] = (char)toupper((unsigned char)token[i]);
        }
        up[i] = '\0';
        strcat(result, up);
        token = strtok(NULL, ",");
    }
    printf("%s\n", result);
    return 0;
}
