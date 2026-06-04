#include <stdio.h>
#include <string.h>

static int my_atoi(const char *s) {
    int sign = 1;
    int value = 0;
    size_t i = 0;
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }
    for (; s[i] >= '0' && s[i] <= '9'; i++)
        value = value * 10 + (s[i] - '0');
    return sign * value;
}

static void my_itoa(int n, char *out) {
    char tmp[16];
    size_t t = 0;
    size_t o = 0;
    int negative = 0;
    unsigned int u;

    if (n < 0) {
        negative = 1;
        u = (unsigned int)(-(long)n);
    } else {
        u = (unsigned int)n;
    }

    do {
        tmp[t++] = (char)('0' + (u % 10));
        u /= 10;
    } while (u != 0);

    if (negative)
        out[o++] = '-';
    while (t > 0)
        out[o++] = tmp[--t];
    out[o] = '\0';
}

int main(void) {
    int parsed = my_atoi("-42");
    char formatted[16];
    my_itoa(parsed, formatted);
    printf("%d %s\n", parsed, formatted);
    return 0;
}
