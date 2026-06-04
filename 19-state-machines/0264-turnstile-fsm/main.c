#include <stdio.h>

enum state { LOCKED, UNLOCKED };
enum event { COIN, PUSH };

static enum state step(enum state s, enum event e) {
    if (s == LOCKED && e == COIN) return UNLOCKED;
    if (s == UNLOCKED && e == PUSH) return LOCKED;
    return s;
}

int main(void) {
    enum state s = LOCKED;
    enum event events[] = { COIN, PUSH, PUSH };
    for (int i = 0; i < 3; i++) {
        s = step(s, events[i]);
        printf("%s%s", s == LOCKED ? "locked" : "unlocked", i < 2 ? " " : "\n");
    }
    return 0;
}
