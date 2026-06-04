#include <stdio.h>

/* fails on attempts 1 and 2, succeeds on attempt 3 */
static int operation(int attempt) {
    return attempt >= 3;
}

int main(void) {
    int attempts = 5;
    for (int i = 1; i <= attempts; i++) {
        if (operation(i)) {
            printf("ok after %d\n", i);
            break;
        }
    }
    return 0;
}
