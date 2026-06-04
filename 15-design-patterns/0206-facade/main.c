#include <stdio.h>

static void sub1_init(void) {}
static void sub2_init(void) {}
static void sub3_init(void) {}

const char *facade_start(void) {
    sub1_init();
    sub2_init();
    sub3_init();
    return "ready";
}

int main(void) {
    printf("%s\n", facade_start());
    return 0;
}
