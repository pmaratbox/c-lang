#include <stdio.h>

typedef struct {
    int id;
    const char *name;
} Person;

const char *lookup(Person *index, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (index[i].id == id) {
            return index[i].name;
        }
    }
    return NULL;
}

int main(void) {
    Person people[] = {{1, "alice"}, {2, "bob"}};
    int n = sizeof(people) / sizeof(people[0]);

    printf("id 2: %s\n", lookup(people, n, 2));
    return 0;
}
