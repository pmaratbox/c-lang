#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *name;
    int age;
} Person;

static int by_age(const void *a, const void *b) {
    const Person *pa = a;
    const Person *pb = b;
    return (pa->age > pb->age) - (pa->age < pb->age);
}

int main(void) {
    Person people[] = {
        { "alice", 30 },
        { "bob", 25 },
    };
    size_t n = sizeof(people) / sizeof(people[0]);
    qsort(people, n, sizeof(people[0]), by_age);
    for (size_t i = 0; i < n; i++) {
        printf("%s%s", i ? " " : "", people[i].name);
    }
    printf("\n");
    return 0;
}
