# 0016 — Generics

Define a generic `first` function that returns the first element of a list, then call it on a list of integers and a list of strings to show one definition working at two types. C has no generics, so the closest tool is the *preprocessor*: `#define first(arr) ((arr)[0])` is a textual macro that expands at any element type because it does no type checking at all. The caller still supplies the right `printf` format (`%d` vs `%s`) — the macro just substitutes text. (C11's `_Generic` and `void *` are the other, more typed routes.)

## Run

    make && ./generics
