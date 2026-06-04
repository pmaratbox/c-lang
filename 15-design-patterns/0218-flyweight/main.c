#include <stdio.h>

typedef struct {
    char key;
} Flyweight;

static Flyweight pool[128];
static int created[128];
static int count;

Flyweight *get_flyweight(char key) {
    if (!created[(int)key]) {
        pool[(int)key].key = key;
        created[(int)key] = 1;
        count++;
    }
    return &pool[(int)key];
}

int main(void) {
    char keys[] = {'a', 'b', 'a'};
    for (int i = 0; i < 3; i++) {
        get_flyweight(keys[i]);
    }
    printf("%d\n", count);
    return 0;
}
