# 0046 — Number Bases & Radix

Print the integer `255` in hexadecimal, octal, and binary, producing `hex: ff`, `oct: 377`, and `bin: 11111111`. `printf` has `%x` and `%o`, but C has no binary conversion specifier, so binary is built bit by bit by shifting and masking from the high bit down.

## Run

    make && ./bases
