#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main(void) {
    printf("3 + 4 = %d\n", add(3, 4));
    return 0;
}
