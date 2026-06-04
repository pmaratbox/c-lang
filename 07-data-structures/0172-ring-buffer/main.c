#include <stdio.h>

#define CAP 3

int main(void) {
    int buf[CAP];
    int head = 0;   /* index of oldest */
    int count = 0;

    for (int v = 1; v <= 5; v++) {
        int tail = (head + count) % CAP;
        buf[tail] = v;
        if (count < CAP) count++;
        else head = (head + 1) % CAP;   /* overwrite oldest */
    }

    for (int i = 0; i < count; i++)
        printf("%d%s", buf[(head + i) % CAP], i + 1 < count ? " " : "\n");
    return 0;
}
