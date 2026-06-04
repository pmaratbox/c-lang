#include <stdio.h>

int main(void) {
    int err = 1; /* simulate a thrown error */
    if (err) {
        printf("caught\n");
    }
    printf("cleanup\n"); /* always runs, like a finally block */
    return 0;
}
