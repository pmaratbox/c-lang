#include <stdio.h>

typedef struct {
    const char *theme;
} ThemeFactory;

void make_button(const ThemeFactory *f, char *out) {
    sprintf(out, "%s-button", f->theme);
}

void make_checkbox(const ThemeFactory *f, char *out) {
    sprintf(out, "%s-checkbox", f->theme);
}

int main(void) {
    ThemeFactory dark = {"dark"};
    char button[32];
    char checkbox[32];
    make_button(&dark, button);
    make_checkbox(&dark, checkbox);
    printf("%s %s\n", button, checkbox);
    return 0;
}
