#include <stdio.h>

struct Address {
    const char *city;
};

struct Person {
    const char *name;
    struct Address address;
};

int main(void) {
    struct Person person = { "Ada", { "London" } };
    printf("%s\n", person.address.city);
    return 0;
}
