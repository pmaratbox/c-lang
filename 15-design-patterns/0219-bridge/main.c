#include <stdio.h>

typedef struct {
    const char *(*name)(void);
} Color;

static const char *red_name(void) {
    return "red";
}

typedef struct {
    Color *color;
} Circle;

void describe(const Circle *c, char *out) {
    sprintf(out, "%s circle", c->color->name());
}

int main(void) {
    Color red = {red_name};
    Circle circle = {&red};
    char out[32];
    describe(&circle, out);
    printf("%s\n", out);
    return 0;
}
