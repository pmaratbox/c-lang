#include <stdio.h>

typedef struct {
    int *counter;
    int amount;
} AddCommand;

void execute(AddCommand *cmd) {
    *cmd->counter += cmd->amount;
}

void undo(AddCommand *cmd) {
    *cmd->counter -= cmd->amount;
}

int main(void) {
    int counter = 0;
    AddCommand cmd = {&counter, 5};
    execute(&cmd);
    printf("%d ", counter);
    undo(&cmd);
    printf("%d\n", counter);
    return 0;
}
