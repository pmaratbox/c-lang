#include <stdio.h>
#include <string.h>

static int is_balanced(const char *s) {
    char stack[64];
    int top = 0;
    for (size_t i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[top++] = s[i];
        } else if (s[i] == ')') {
            if (top == 0) return 0;
            top--;
        }
    }
    return top == 0;
}

int main(void) {
    const char *inputs[] = {"(())", "(()"};
    for (int i = 0; i < 2; i++) {
        printf("%s\n", is_balanced(inputs[i]) ? "yes" : "no");
    }
    return 0;
}
