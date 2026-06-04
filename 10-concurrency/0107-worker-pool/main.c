#include <stdio.h>
#include <pthread.h>

typedef struct {
    int input;
    int output;
} task;

static void *worker(void *arg) {
    task *t = arg;
    t->output = t->input * t->input;
    return NULL;
}

int main(void) {
    task tasks[4];
    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        tasks[i].input = i + 1;
        pthread_create(&threads[i], NULL, worker, &tasks[i]);
    }
    int results[4];
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
        results[i] = tasks[i].output;
    }
    /* sort ascending */
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (results[j] < results[i]) {
                int tmp = results[i];
                results[i] = results[j];
                results[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (i > 0) printf(" ");
        printf("%d", results[i]);
    }
    printf("\n");
    return 0;
}
