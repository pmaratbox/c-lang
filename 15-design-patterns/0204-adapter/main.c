#include <stdio.h>

typedef struct {
    int celsius;
} CelsiusSource;

typedef struct {
    const CelsiusSource *src;
} FahrenheitAdapter;

int fahrenheit(const FahrenheitAdapter *a) {
    return a->src->celsius * 9 / 5 + 32;
}

int main(void) {
    CelsiusSource c = {100};
    FahrenheitAdapter a = {&c};
    printf("%d\n", fahrenheit(&a));
    return 0;
}
