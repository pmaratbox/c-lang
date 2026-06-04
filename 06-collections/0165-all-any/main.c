#include <stdio.h>

int main(void) {
    int xs[] = {2, 4, 6};
    int n = sizeof(xs) / sizeof(xs[0]);

    int all_even = 1;
    int any_odd = 0;
    for (int i = 0; i < n; i++) {
        if (xs[i] % 2 != 0) {
            all_even = 0;
            any_odd = 1;
        }
    }

    printf("%s %s\n", all_even ? "yes" : "no", any_odd ? "yes" : "no");
    return 0;
}
