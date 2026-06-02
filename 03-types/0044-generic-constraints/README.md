# 0044 — Generic Constraints

Write a generic `largest(a, b)` that requires an ordered type, then call it on integers (3 and 9) and on strings (apple and pear), printing `9` and `pear`. C has no generics; the C11 `_Generic` selection is the closest — a compile-time type switch on the first argument that dispatches to `largest_int` or `largest_str`. Each target function is written out by hand.

## Run

    make && ./generics
