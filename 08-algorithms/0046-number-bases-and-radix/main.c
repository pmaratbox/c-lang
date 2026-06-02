#include <stdio.h>

int main(void) {
    int n = 255;
    printf("hex: %x\n", n);
    printf("oct: %o\n", n);
    printf("bin: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
    return 0;
}
