#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d", i * j);
            printf(j < 3 ? " " : "\n");
        }
    }
    return 0;
}
