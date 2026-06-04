#include <stdio.h>

typedef struct Logger {
    void (*log)(struct Logger *self);
    int count;
} Logger;

static void null_log(Logger *self) {
    (void)self;
}

static void real_log(Logger *self) {
    self->count++;
}

int main(void) {
    Logger null_logger = {null_log, 0};
    Logger real_logger = {real_log, 0};
    null_logger.log(&null_logger);
    real_logger.log(&real_logger);
    printf("%d\n", real_logger.count);
    return 0;
}
