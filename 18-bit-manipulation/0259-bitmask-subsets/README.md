# 0259 — Enumerate Submasks

Enumerate all submasks of the mask 5 (101) in descending order `5 4 1 0`. The `sub = (sub - 1) & mask` idiom walks every submask down to zero.

## Run

    make && ./bitmasksubsets
