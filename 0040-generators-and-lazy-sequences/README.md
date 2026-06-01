# 0040 — Generators & Lazy Sequences

Produce an endless lazy sequence of squares and take only the first three, printing `1 4 9`. C has no generators. A function with a `static` local keeps state between calls, so each `next_square()` returns the next value — a hand-rolled iterator. The calls are sequenced into variables because argument evaluation order is unspecified.

## Run

    make && ./gen
