#include <stdio.h>

int main(void) {
    double d = 3.9;
    int i = (int)d;
    float f = (float)i;
    printf("%d %.1f\n", i, f);
    return 0;
}
