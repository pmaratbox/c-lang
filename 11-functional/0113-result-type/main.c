#include <stdio.h>
#include <stdbool.h>

/* A Result is a tagged union: ok carries a value, err carries a message.
   The tag is matched to print each variant. */
typedef struct {
    bool ok;
    int value;
    const char *err;
} Result;

Result safe_div(int a, int b) {
    if (b == 0) {
        Result r = {false, 0, "divide by zero"};
        return r;
    }
    Result r = {true, a / b, NULL};
    return r;
}

void print_result(Result r) {
    if (r.ok) {
        printf("ok: %d\n", r.value);
    } else {
        printf("err: %s\n", r.err);
    }
}

int main(void) {
    print_result(safe_div(10, 2));
    print_result(safe_div(1, 0));
    return 0;
}
