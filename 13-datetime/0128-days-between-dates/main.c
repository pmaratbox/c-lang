#include <stdio.h>

/* days_from_civil: days since 1970-01-01 (Howard Hinnant's algorithm) */
static long days_from_civil(long y, unsigned m, unsigned d) {
    y -= m <= 2;
    long era = (y >= 0 ? y : y - 399) / 400;
    unsigned yoe = (unsigned)(y - era * 400);
    unsigned doy = (153 * (m + (m > 2 ? -3 : 9)) + 2) / 5 + d - 1;
    unsigned doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
    return era * 146097 + (long)doe - 719468;
}

int main(void) {
    long a = days_from_civil(2000, 1, 1);
    long b = days_from_civil(2000, 12, 31);
    printf("%ld\n", b - a);
    return 0;
}
