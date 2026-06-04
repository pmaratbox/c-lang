#include <stdio.h>

int main(void) {
    const char *names[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };
    int start = 6; /* Saturday */
    int result = (start + 3) % 7;
    printf("%s\n", names[result]);
    return 0;
}
