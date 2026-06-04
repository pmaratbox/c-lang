#include <stdio.h>

int main(void) {
    int n = 14;
    int vals[] =    {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *sym[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int count = sizeof(vals) / sizeof(vals[0]);
    for (int i = 0; i < count; i++) {
        while (n >= vals[i]) {
            printf("%s", sym[i]);
            n -= vals[i];
        }
    }
    printf("\n");
    return 0;
}
