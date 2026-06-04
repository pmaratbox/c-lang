#include <stdio.h>

int main(void) {
    double x = 2.0;
    for (int i = 0; i < 50; i++) {
        double next = x - (x * x - 2.0) / (2.0 * x);
        if (next == x) break;
        x = next;
    }
    printf("%.4f\n", x);
    return 0;
}
