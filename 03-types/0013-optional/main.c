#include <stdio.h>

int value_or(const int *p, int fallback) {
    return p != NULL ? *p : fallback;
}

int main(void) {
    int value = 42;
    const int *present = &value;
    const int *absent = NULL;

    printf("present: %d\n", value_or(present, -1));
    printf("absent: %d\n", value_or(absent, -1));
    return 0;
}
