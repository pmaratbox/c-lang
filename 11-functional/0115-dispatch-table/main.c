#include <stdio.h>
#include <string.h>

/* A dispatch table maps names to function pointers; look up by name and
   call the matching binary operation. */
typedef int (*BinOp)(int, int);

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

typedef struct {
    const char *name;
    BinOp op;
} Entry;

static const Entry table[] = {
    {"add", add},
    {"mul", mul},
};

BinOp lookup(const char *name) {
    for (size_t i = 0; i < sizeof table / sizeof table[0]; i++) {
        if (strcmp(table[i].name, name) == 0) {
            return table[i].op;
        }
    }
    return NULL;
}

int main(void) {
    printf("%d %d\n", lookup("add")(3, 4), lookup("mul")(3, 4));
    return 0;
}
