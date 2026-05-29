#include <stdio.h>

struct Person {
    const char *name;
    int age;
};

int main(void) {
    struct Person p = {"Ada", 36};

    printf("name: %s\n", p.name);
    printf("age: %d\n", p.age);
    return 0;
}
