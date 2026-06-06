#include <stdio.h>
#include <string.h>

/* A minimal multi-topic EventEmitter (pub/sub).
   A topic -> list of handlers map, backed by a small fixed array. */

typedef void (*handler_fn)(const char *payload);

#define MAX_SUBS 32

typedef struct {
    const char *topic;
    handler_fn  fn;
    int         active;
} subscription;

static subscription subs[MAX_SUBS];
static int sub_count = 0;

static void on(const char *topic, handler_fn fn) {
    if (sub_count < MAX_SUBS) {
        subs[sub_count].topic  = topic;
        subs[sub_count].fn     = fn;
        subs[sub_count].active = 1;
        sub_count++;
    }
}

static void emit(const char *topic, const char *payload) {
    for (int i = 0; i < sub_count; i++) {
        if (subs[i].active && strcmp(subs[i].topic, topic) == 0) {
            subs[i].fn(payload);
        }
    }
}

static void off(const char *topic, handler_fn fn) {
    for (int i = 0; i < sub_count; i++) {
        if (subs[i].active && subs[i].fn == fn &&
            strcmp(subs[i].topic, topic) == 0) {
            subs[i].active = 0;
        }
    }
}

static void greet_handler(const char *payload) {
    printf("hi %s\n", payload);
}

static void bye_handler(const char *payload) {
    printf("bye %s\n", payload);
}

int main(void) {
    on("greet", greet_handler);
    on("bye", bye_handler);

    emit("greet", "ada");
    emit("bye", "ada");

    off("greet", greet_handler);
    emit("greet", "x"); /* handler removed -> nothing */

    return 0;
}
