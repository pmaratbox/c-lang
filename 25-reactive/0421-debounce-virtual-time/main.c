#include <stdio.h>
#include <string.h>

/* Virtual-time scheduler: priority queue of (time, seq, callback). */

typedef void (*Callback)(const char *value);

typedef struct {
    long time;
    long seq;
    Callback cb;
    char value[8];
    int dead;
} Task;

#define MAX_TASKS 32

static Task tasks[MAX_TASKS];
static int task_count = 0;
static long seq_counter = 0;
static long virtual_clock = 0;

/* Returns a token (index) for the scheduled task so it can be cancelled. */
static int schedule(long time, Callback cb, const char *value) {
    int i = task_count++;
    tasks[i].time = time;
    tasks[i].seq = seq_counter++;
    tasks[i].cb = cb;
    strncpy(tasks[i].value, value, sizeof(tasks[i].value) - 1);
    tasks[i].value[sizeof(tasks[i].value) - 1] = '\0';
    tasks[i].dead = 0;
    return i;
}

static void cancel(int token) {
    if (token >= 0 && token < task_count) {
        tasks[token].dead = 1;
    }
}

/* Pop the smallest live (time, seq); -1 when none remain. */
static int pop_next(void) {
    int best = -1;
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].dead) continue;
        if (best == -1 ||
            tasks[i].time < tasks[best].time ||
            (tasks[i].time == tasks[best].time && tasks[i].seq < tasks[best].seq)) {
            best = i;
        }
    }
    return best;
}

static void run(void) {
    int idx;
    while ((idx = pop_next()) != -1) {
        tasks[idx].dead = 1;
        virtual_clock = tasks[idx].time;
        tasks[idx].cb(tasks[idx].value);
    }
}

/* Observer: prints each emitted value. */
static void emit(const char *value) {
    printf("%s\n", value);
}

/* debounce(window): on each value cancel the pending emit and reschedule. */
static int pending = -1;
static const long WINDOW = 30;

static void on_value(const char *value) {
    if (pending != -1) {
        cancel(pending);
    }
    pending = schedule(virtual_clock + WINDOW, emit, value);
}

int main(void) {
    /* Source emits "a"@10, "b"@20, "c"@100. */
    schedule(10, on_value, "a");
    schedule(20, on_value, "b");
    schedule(100, on_value, "c");

    run();
    return 0;
}
