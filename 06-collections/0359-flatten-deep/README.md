# 0359 — Flatten Deeply

Flatten the arbitrarily nested structure [1,[2,[3,4]],5] into `1 2 3 4 5`. In C the nesting is modeled as a tree of tagged-union nodes that a recursive walk emits in order.

## Run

    make && ./flattendeep
