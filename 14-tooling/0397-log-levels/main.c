#include <stdio.h>

enum { INFO, WARN, ERROR };

static const char *names[] = { "INFO", "WARN", "ERROR" };

static void emit(int threshold, int level, const char *msg) {
    if (level >= threshold) {
        printf("%s: %s\n", names[level], msg);
    }
}

int main(void) {
    int threshold = WARN;
    emit(threshold, INFO, "i");
    emit(threshold, WARN, "w");
    emit(threshold, ERROR, "e");
    return 0;
}
