#include <stdio.h>

int main(void) {
    int data[] = { 3, 1, 2 };
    size_t n = sizeof data / sizeof data[0];

    for (size_t i = 0; i < n; i++) {
        for (int j = 0; j < data[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
