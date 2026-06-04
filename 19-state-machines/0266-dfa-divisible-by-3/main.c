#include <stdio.h>

static int divisible_by_3(const char *bits) {
    int state = 0;
    for (const char *p = bits; *p; p++) {
        int b = *p - '0';
        state = (state * 2 + b) % 3;
    }
    return state == 0;
}

int main(void) {
    printf("%s ", divisible_by_3("110") ? "yes" : "no");
    printf("%s\n", divisible_by_3("100") ? "yes" : "no");
    return 0;
}
