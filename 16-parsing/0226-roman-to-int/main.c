#include <stdio.h>

static int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int main(void) {
    const char *s = "XIV";
    int total = 0;
    for (const char *p = s; *p; p++) {
        int v = value(*p);
        int next = value(*(p + 1));
        if (next > v) total -= v;
        else total += v;
    }
    printf("%d\n", total);
    return 0;
}
