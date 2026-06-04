#include <stdio.h>

/* A trampoline returns a thunk (more=1 plus next state) instead of
   recursing; the driver loops until done, so the stack stays flat. */
typedef struct {
    int more;   /* 1 = keep bouncing, 0 = done */
    int n;      /* remaining counter */
    int acc;    /* running sum */
} Bounce;

static Bounce step(Bounce b) {
    if (b.n == 0) {
        b.more = 0;
        return b;
    }
    b.acc += b.n;
    b.n -= 1;
    return b;
}

int main(void) {
    Bounce b = {1, 100, 0};
    while (b.more) b = step(b);
    printf("%d\n", b.acc);
    return 0;
}
