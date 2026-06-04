#include <stdio.h>

static int next(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int main(void) {
    int slow = 19, fast = 19;
    do {
        slow = next(slow);
        fast = next(next(fast));
    } while (slow != fast);
    printf("%s\n", slow == 1 ? "yes" : "no");
    return 0;
}
