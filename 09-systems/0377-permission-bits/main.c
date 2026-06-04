#include <stdio.h>

int main(void) {
    unsigned bits = 0b101;
    char rwx[4];
    rwx[0] = (bits & 0b100) ? 'r' : '-';
    rwx[1] = (bits & 0b010) ? 'w' : '-';
    rwx[2] = (bits & 0b001) ? 'x' : '-';
    rwx[3] = '\0';
    printf("%s\n", rwx);
    return 0;
}
