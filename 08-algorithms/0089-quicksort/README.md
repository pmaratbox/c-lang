# 0089 — Quicksort

Sort the list `3, 1, 4, 1, 5, 2` using quicksort (partition around a pivot, then recurse on each side) and print the result: `1 1 2 3 4 5`. An in-place Lomuto partition (last element as pivot) sorts the array within `[lo, hi]` index ranges, recursing on each side of the pivot.

## Run

    make && ./quicksort
