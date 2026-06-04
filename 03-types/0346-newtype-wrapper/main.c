#include <stdio.h>

typedef struct { int raw; } UserId;
typedef struct { int raw; } ProductId;

int main(void) {
    UserId u = { .raw = 1 };
    ProductId p = { .raw = 2 };
    printf("user-%d prod-%d\n", u.raw, p.raw);
    return 0;
}
