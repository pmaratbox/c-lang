#include <stdio.h>

typedef struct {
    int value;
} Config;

static Config *get_instance(void) {
    static Config instance = { .value = 0 };
    return &instance;
}

int main(void) {
    Config *a = get_instance();
    Config *b = get_instance();
    printf("same: %s\n", a == b ? "yes" : "no");
    return 0;
}
