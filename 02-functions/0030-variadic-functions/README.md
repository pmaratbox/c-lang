# 0030 — Variadic Functions

Define a function that accepts a variable number of integer arguments and returns their total, then call it with `1, 2, 3` to print `sum: 6`. C variadics use `<stdarg.h>`: the count comes first so the callee knows how many `va_arg` reads to make between `va_start` and `va_end`. The arguments are untyped, so a count or sentinel is mandatory.

## Run

    make && ./variadic
