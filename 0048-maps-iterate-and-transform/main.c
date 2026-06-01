#include <stdio.h>

struct Entry {
    const char *key;
    int value;
};

int main(void) {
    struct Entry scores[] = {{"a", 1}, {"b", 2}, {"c", 3}};
    int total = 0;
    for (size_t i = 0; i < sizeof(scores) / sizeof(scores[0]); i++) {
        total += scores[i].value;
    }
    printf("sum: %d\n", total);
    return 0;
}
