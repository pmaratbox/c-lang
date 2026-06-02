#include <stdio.h>

int main(void) {
    int temps[] = {100, 0};
    for (int i = 0; i < 2; i++) {
        int c = temps[i];
        int f = c * 9 / 5 + 32;
        printf("%dC = %dF\n", c, f);
    }
    return 0;
}
