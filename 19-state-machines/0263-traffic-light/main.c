#include <stdio.h>

enum light { RED, GREEN, YELLOW };

static enum light next(enum light s) {
    switch (s) {
        case RED:    return GREEN;
        case GREEN:  return YELLOW;
        case YELLOW: return RED;
    }
    return RED;
}

static const char *name(enum light s) {
    switch (s) {
        case RED:    return "red";
        case GREEN:  return "green";
        case YELLOW: return "yellow";
    }
    return "?";
}

int main(void) {
    enum light s = RED;
    for (int i = 0; i < 4; i++) {
        s = next(s);
        printf("%s%s", name(s), i < 3 ? " " : "\n");
    }
    return 0;
}
