#include <stdio.h>

static int is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int days_in_february(int year) {
    return is_leap(year) ? 29 : 28;
}

int main(void) {
    printf("%d %d\n", days_in_february(2000), days_in_february(2001));
    return 0;
}
