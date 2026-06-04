#include <stdio.h>

int main(void) {
    const char *name = "Ada";
    int age = 36;
    printf("{\"name\":\"%s\",\"age\":%d}\n", name, age);
    return 0;
}
