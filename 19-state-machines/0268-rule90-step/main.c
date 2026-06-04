#include <stdio.h>
#include <string.h>

int main(void) {
    const char *row = "00100";
    int len = (int)strlen(row);
    for (int i = 0; i < len; i++) {
        int left  = i > 0 ? row[i - 1] - '0' : 0;
        int right = i < len - 1 ? row[i + 1] - '0' : 0;
        putchar((left ^ right) ? '1' : '0');
    }
    putchar('\n');
    return 0;
}
