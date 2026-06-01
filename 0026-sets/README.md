# 0026 — Sets

Build a set from `1, 2, 2, 3` so the duplicate collapses, then print its `size: 3` and whether it contains `2` (`has 2: yes`) and `5` (`has 5: no`). C has no set type. For a small, known integer range a boolean *presence array* works: index `i` records whether `i` is in the set, so duplicate inserts are idempotent and membership is a direct lookup. General sets need a hash table.

## Run

    make && ./sets
