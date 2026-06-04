#include <stdio.h>
#include <string.h>

int main(void) {
    const char *a = "abcd";
    const char *b = "cdab";
    int is_rotation = 0;
    if (strlen(a) == strlen(b)) {
        char doubled[256];
        snprintf(doubled, sizeof(doubled), "%s%s", a, a);
        if (strstr(doubled, b) != NULL) is_rotation = 1;
    }
    printf("%s\n", is_rotation ? "yes" : "no");
    return 0;
}
