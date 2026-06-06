#include <stdio.h>

/* An observer that enforces the next*-then-terminal contract.
   The first terminal (complete or error) sets a "stopped" flag,
   after which next() and further terminals are no-ops. */
typedef struct {
    int stopped;
} Observer;

static void obs_next(Observer *o, int value) {
    if (o->stopped) return;
    printf("%d\n", value);
}

static void obs_complete(Observer *o) {
    if (o->stopped) return;
    o->stopped = 1;
    printf("complete\n");
}

int main(void) {
    Observer o = { 0 };
    obs_next(&o, 1);
    obs_next(&o, 2);
    obs_complete(&o);
    obs_next(&o, 3); /* ignored: arrives after the terminal */
    return 0;
}
