#include <stdio.h>

static int is_perfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0) sum += i;
    return sum == n;
}

int main(void) {
    printf("%s %s\n", is_perfect(6) ? "yes" : "no",
                      is_perfect(8) ? "yes" : "no");
    return 0;
}
