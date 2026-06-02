# 0024 — Sorting & Comparators

Sort `[3, 1, 2]` ascending, then again with a custom comparator that reverses the order, printing `asc: 1 2 3` and `desc: 3 2 1`. `qsort` is the standard library's generic sort: it takes the element size and a comparator returning negative/zero/positive via `void *` operands that must be cast back to `int *`. Swapping the operands in the comparator yields descending order.

## Run

    make && ./sorting
