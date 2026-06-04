#include <stdio.h>

/* class-level (static) counter */
static int widget_count = 0;

typedef struct {
    int id;
} Widget;

/* "constructor" increments the shared counter */
static Widget widget_new(void) {
    Widget w = { ++widget_count };
    return w;
}

int main(void) {
    Widget a = widget_new();
    Widget b = widget_new();
    Widget c = widget_new();
    (void)a; (void)b; (void)c;
    printf("%d\n", widget_count);
    return 0;
}
