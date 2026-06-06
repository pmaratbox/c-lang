#include <stdio.h>

/* A minimal push-based Observable built from scratch. */

typedef struct {
    void (*next)(int value);
    void (*complete)(void);
} Observer;

static void on_next(int value) {
    printf("%d\n", value);
}

static void on_complete(void) {
    printf("done\n");
}

/* The Observable is a function taking an observer; on subscribe it
   pushes 1, 2, 3 and then signals completion. */
static void observable(Observer *observer) {
    observer->next(1);
    observer->next(2);
    observer->next(3);
    observer->complete();
}

int main(void) {
    Observer observer = { on_next, on_complete };
    observable(&observer);
    return 0;
}
