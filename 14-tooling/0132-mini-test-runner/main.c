#include <stdio.h>

static int test_addition(void)    { return 1 + 1 == 2; }
static int test_subtraction(void) { return 5 - 3 == 2; }
static int test_multiply(void)    { return 2 * 4 == 8; }

int main(void) {
    int (*tests[])(void) = { test_addition, test_subtraction, test_multiply };
    int n = (int)(sizeof(tests) / sizeof(tests[0]));
    int passed = 0, failed = 0;
    for (int i = 0; i < n; i++) {
        if (tests[i]()) passed++;
        else failed++;
    }
    printf("%d passed, %d failed\n", passed, failed);
    return 0;
}
