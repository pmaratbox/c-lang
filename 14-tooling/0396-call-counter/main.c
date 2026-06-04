#include <stdio.h>

static int counter = 0;

static void work(void) {
    counter++;
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        work();
    }
    printf("calls: %d\n", counter);
    return 0;
}
