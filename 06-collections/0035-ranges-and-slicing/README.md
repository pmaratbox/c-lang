# 0035 — Ranges & Slicing

From the list `[10, 20, 30, 40, 50]`, take the sub-sequence at indices 1 through 4 (exclusive) and print `slice: 20 30 40`. C has no slice type; you work with a pointer and a length. Iterating indices `1` to `3` (or passing `&nums[1]` with a length of 3) is the manual equivalent, sharing the original storage.

## Run

    make && ./ranges
