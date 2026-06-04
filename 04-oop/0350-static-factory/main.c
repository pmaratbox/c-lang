#include <stdio.h>

typedef struct {
    int r, g, b;
} Color;

static int hex_pair(const char *s) {
    int hi = (s[0] <= '9') ? s[0] - '0' : (s[0] | 0x20) - 'a' + 10;
    int lo = (s[1] <= '9') ? s[1] - '0' : (s[1] | 0x20) - 'a' + 10;
    return hi * 16 + lo;
}

/* static factory: build a Color from a "#rrggbb" string */
static Color color_from_hex(const char *hex) {
    const char *p = hex + 1; /* skip '#' */
    Color c = { hex_pair(p), hex_pair(p + 2), hex_pair(p + 4) };
    return c;
}

int main(void) {
    Color c = color_from_hex("#ff0000");
    printf("%d %d %d\n", c.r, c.g, c.b);
    return 0;
}
