#include <stdio.h>
#include <stdbool.h>

static const char *bs(bool v) {
    return v ? "true" : "false";
}

int main(void) {
    bool rows[4][2] = {{true, true}, {true, false}, {false, true}, {false, false}};
    for (int i = 0; i < 4; i++) {
        bool a = rows[i][0];
        bool b = rows[i][1];
        printf("%s %s %s %s %s\n", bs(a), bs(b), bs(a && b), bs(a || b), bs(a != b));
    }
    return 0;
}
