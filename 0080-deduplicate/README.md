# 0080 — Deduplicate

Remove duplicates from `1, 2, 2, 3, 1`, keeping the first occurrence of each in order, and print `1 2 3`. With no set type, each value is checked against those already kept (a linear scan) and appended only if new — O(n^2) but simple.

## Run

    make && ./dedup
