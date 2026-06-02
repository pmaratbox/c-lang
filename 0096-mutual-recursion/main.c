#include <stdio.h>

int is_odd(int n);

int is_even(int n) {
    if (n == 0) return 1;
    return is_odd(n - 1);
}

int is_odd(int n) {
    if (n == 0) return 0;
    return is_even(n - 1);
}

int main(void) {
    int vals[] = {4, 3};
    for (int i = 0; i < 2; i++) {
        printf("%s\n", is_even(vals[i]) ? "even" : "odd");
    }
    return 0;
}
