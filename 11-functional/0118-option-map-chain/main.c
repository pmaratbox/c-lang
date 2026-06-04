#include <stdio.h>
#include <stdbool.h>

/* An Option is a present flag plus a value. map applies a function only
   when present; unwrap_or supplies a fallback when absent. */
typedef struct {
    bool present;
    int value;
} Option;

typedef int (*Fn)(int);

int add_two(int x) { return x + 2; }

Option some(int v) { Option o = {true, v}; return o; }
Option none(void) { Option o = {false, 0}; return o; }

Option map_opt(Fn f, Option o) {
    if (o.present) {
        return some(f(o.value));
    }
    return o;
}

int main(void) {
    Option present = map_opt(add_two, some(10));
    Option absent = map_opt(add_two, none());
    if (present.present) {
        printf("%d ", present.value);
    } else {
        printf("none ");
    }
    if (absent.present) {
        printf("%d\n", absent.value);
    } else {
        printf("none\n");
    }
    return 0;
}
