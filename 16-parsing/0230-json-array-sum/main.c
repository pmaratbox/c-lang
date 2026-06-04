#include <stdio.h>
#include <ctype.h>

int main(void) {
    const char *s = "[1,2,3]";
    int sum = 0;
    int n = 0;
    int have = 0;
    for (const char *p = s; *p; p++) {
        if (isdigit((unsigned char)*p)) {
            n = n * 10 + (*p - '0');
            have = 1;
        } else if (have) {
            sum += n;
            n = 0;
            have = 0;
        }
    }
    if (have) sum += n;
    printf("%d\n", sum);
    return 0;
}
