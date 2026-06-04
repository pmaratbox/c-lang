#include <stdio.h>

typedef struct Shape {
    const char *(*describe)(void);
} Shape;

static const char *circle_describe(void)   { return "circle"; }
static const char *square_describe(void)   { return "square"; }
static const char *triangle_describe(void) { return "triangle"; }

int main(void) {
    Shape shapes[] = {
        { circle_describe },
        { square_describe },
        { triangle_describe },
    };
    int n = sizeof(shapes) / sizeof(shapes[0]);
    for (int i = 0; i < n; i++) {
        printf("%s%s", shapes[i].describe(), i + 1 < n ? " " : "\n");
    }
    return 0;
}
