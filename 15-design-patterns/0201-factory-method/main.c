#include <stdio.h>
#include <string.h>

typedef struct {
    const char *kind;
} Shape;

Shape make_shape(const char *name) {
    Shape s;
    if (strcmp(name, "circle") == 0) {
        s.kind = "circle";
    } else {
        s.kind = "square";
    }
    return s;
}

int main(void) {
    Shape a = make_shape("circle");
    Shape b = make_shape("square");
    printf("%s %s\n", a.kind, b.kind);
    return 0;
}
