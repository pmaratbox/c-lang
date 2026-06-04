#include <stdio.h>

int main(void) {
    int y = 2000, m = 1, d = 1;
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int K = y % 100;
    int J = y / 100;
    int h = (d + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    /* h: 0=Saturday, 1=Sunday, ... 6=Friday */
    const char *names[] = {
        "Saturday", "Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday"
    };
    printf("%s\n", names[h]);
    return 0;
}
