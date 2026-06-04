#include <stdio.h>

enum Perm {
    READ = 1,
    WRITE = 2
};

int main(void) {
    int flags = READ | WRITE;
    printf("%d %s\n", flags, (flags & WRITE) != 0 ? "yes" : "no");
    return 0;
}
