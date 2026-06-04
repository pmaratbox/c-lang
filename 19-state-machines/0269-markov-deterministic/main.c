#include <stdio.h>

int main(void) {
    /* next[state]: A=0 -> B=1 -> C=2 -> A=0 */
    int next[] = { 1, 2, 0 };
    const char *names[] = { "A", "B", "C" };
    int state = 0; /* A */
    for (int i = 0; i < 3; i++) {
        state = next[state];
        printf("%s%s", names[state], i < 2 ? " " : "\n");
    }
    return 0;
}
