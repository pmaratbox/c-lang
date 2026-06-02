# 0029 — Bitwise Operations

Compute bitwise AND, OR, and XOR on `6` and `3`, plus a left shift of `6` by one bit, printing `and: 2`, `or: 7`, `xor: 5`, and `shift: 12`. The operators `&`, `|`, `^`, and `<<` act on C's integer types; `6 << 1` doubles to 12. Shifting a signed value left into or past the sign bit is undefined behavior, so bit-twiddling often uses `unsigned`.

## Run

    make && ./bitwise
