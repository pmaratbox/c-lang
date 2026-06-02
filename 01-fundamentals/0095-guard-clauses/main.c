#include <stdio.h>

const char *classify(int n) {
    if (n < 0) return "negative";
    if (n == 0) return "zero";
    return "positive";
}

int main(void) {
    int vals[] = {-1, 0, 5};
    for (int i = 0; i < 3; i++) {
        printf("%s\n", classify(vals[i]));
    }
    return 0;
}
