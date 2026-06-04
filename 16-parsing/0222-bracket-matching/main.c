#include <stdio.h>
#include <string.h>

static int balanced(const char *s) {
    char stack[64];
    int top = 0;
    for (const char *p = s; *p; p++) {
        char c = *p;
        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == 0) return 0;
            char open = stack[--top];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) return 0;
        }
    }
    return top == 0;
}

int main(void) {
    printf("%s %s\n", balanced("([{}])") ? "yes" : "no",
                      balanced("([)]") ? "yes" : "no");
    return 0;
}
