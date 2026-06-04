#include <stdio.h>
#include <string.h>

int main(void) {
    const char *xs[] = {"a", "bbb", "cc"};
    int n = sizeof(xs) / sizeof(xs[0]);

    const char *best = xs[0];
    for (int i = 1; i < n; i++) {
        if (strlen(xs[i]) > strlen(best)) {
            best = xs[i];
        }
    }

    printf("%s\n", best);
    return 0;
}
