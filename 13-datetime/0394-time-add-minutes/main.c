#include <stdio.h>

int main(void) {
    int hour = 10, minute = 45;
    int total = hour * 60 + minute + 90;
    total %= 24 * 60;
    printf("%02d:%02d\n", total / 60, total % 60);
    return 0;
}
