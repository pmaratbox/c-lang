#include <stdio.h>

/* A lens pairs a getter and an immutable setter over nested data.
   Here the focus is field b inside {a:{b}}. */
typedef struct { int b; } Inner;
typedef struct { Inner a; } Outer;

static int  b_get(Outer o)        { return o.a.b; }
static Outer b_set(Outer o, int v) { o.a.b = v; return o; } /* returns a copy */

int main(void) {
    Outer o = {{1}};
    int got = b_get(o);
    Outer o2 = b_set(o, 2);   /* o is unchanged; o2 is the updated copy */
    printf("%d %d\n", got, b_get(o2));
    return 0;
}
