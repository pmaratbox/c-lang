#include <stdio.h>

/* An observer receives pushed values. */
typedef struct {
    void (*next)(int value);
} Observer;

/* A subscription tracks whether the consumer is still listening. */
typedef struct {
    int closed;
} Subscription;

static void unsubscribe(Subscription *sub) {
    sub->closed = 1;
}

/* The source pushes 1,2,3,4 but checks "closed" before each next. */
static void source_subscribe(Observer *obs, Subscription *sub) {
    int values[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        if (sub->closed) {
            return;
        }
        obs->next(values[i]);
    }
}

static Subscription *g_sub;

static void on_next(int value) {
    printf("%d\n", value);
    /* Consumer unsubscribes after receiving 2. */
    if (value == 2) {
        unsubscribe(g_sub);
    }
}

int main(void) {
    Subscription sub = { .closed = 0 };
    g_sub = &sub;
    Observer obs = { .next = on_next };
    source_subscribe(&obs, &sub);
    return 0;
}
