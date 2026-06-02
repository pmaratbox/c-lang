#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int values[] = {1, 2, 2, 3};
    bool present[16] = {false};
    int size = 0;
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        int v = values[i];
        if (!present[v]) {
            present[v] = true;
            size++;
        }
    }
    printf("size: %d\n", size);
    printf("has 2: %s\n", present[2] ? "yes" : "no");
    printf("has 5: %s\n", present[5] ? "yes" : "no");
    return 0;
}
