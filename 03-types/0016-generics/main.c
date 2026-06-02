#include <stdio.h>

#define first(arr) ((arr)[0])

int main(void) {
    int ints[] = {1, 2, 3};
    const char *strs[] = {"a", "b", "c"};

    printf("first int: %d\n", first(ints));
    printf("first string: %s\n", first(strs));
    return 0;
}
