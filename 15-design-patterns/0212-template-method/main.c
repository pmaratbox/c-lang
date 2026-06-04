#include <stdio.h>

const char *step(void) {
    return "work";
}

void run(const char *(*step_fn)(void)) {
    printf("start %s end\n", step_fn());
}

int main(void) {
    run(step);
    return 0;
}
