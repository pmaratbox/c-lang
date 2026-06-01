# 0023 — Modules & Imports

Define `square(n)` in a separate `mathutil` module and import it from the main program, printing `square(8) = 64` across the module boundary. C has no module system — the unit of reuse is a header plus a translation unit. `mathutil.h` *declares* `square` (the interface), `mathutil.c` *defines* it, and `main.c` includes the header; the Makefile compiles and links both `.c` files. The include guard prevents double declaration.

## Run

    make && ./modules
