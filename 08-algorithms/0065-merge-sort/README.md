# 0065 — Merge Sort

Sort the list `3, 1, 4, 1, 5, 2` using merge sort (recursively split in half, then merge the sorted halves) and print the result: `1 1 2 3 4 5`. With no growable list, this sorts the array in place over `[lo, hi)` index ranges, merging into a scratch `buf` and copying back.

## Run

    make && ./mergesort
