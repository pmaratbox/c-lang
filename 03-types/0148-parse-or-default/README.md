# 0148 — Parse or Default

Parse "42" to 42 and "x" (invalid) to a default 0, printing `42 0`. In C, `strtol` reports failure via its end pointer, so check it before using the result.

## Run

    make && ./ordefault
