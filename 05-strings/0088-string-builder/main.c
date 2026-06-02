#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3};
    char buf[64] = "";
    int len = 0;
    for (int i = 0; i < 3; i++) {
        if (i > 0) buf[len++] = '-';
        len += sprintf(buf + len, "%d", nums[i]);
    }
    printf("%s\n", buf);
    return 0;
}
