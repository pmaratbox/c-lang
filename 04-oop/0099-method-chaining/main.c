#include <stdio.h>

typedef struct {
    int value;
} Calc;

static Calc start(int v) {
    Calc c = {v};
    return c;
}

static Calc add(Calc c, int n) {
    c.value += n;
    return c;
}

static Calc multiply(Calc c, int n) {
    c.value *= n;
    return c;
}

int main(void) {
    Calc c = multiply(add(start(5), 3), 2);
    printf("%d\n", c.value);
    return 0;
}
