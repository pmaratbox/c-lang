# 0002 — Variables & basic types

Declare an `int`, a `double`, a C-string (`const char *`), and a `bool`,
then print each with the appropriate `printf` conversion specifier.
`bool` lives in `<stdbool.h>` (C99+); `printf` has no boolean specifier,
so a ternary picks the literal `"true"`/`"false"` string.

## Run

    make && ./variables
