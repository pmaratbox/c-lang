#include <stdio.h>

int main(void) {
    int n = 5;
    int a = 1, b = 1;
    for (int i = 0; i < n; i++) {
        int next = a + b;
        a = b;
        b = next;
    }
    printf("%d\n", a);
    return 0;
}
