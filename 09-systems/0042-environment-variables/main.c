#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *value = getenv("LESSON_ENV_VAR");
    if (value == NULL) {
        value = "default";
    }
    printf("value: %s\n", value);
    return 0;
}
