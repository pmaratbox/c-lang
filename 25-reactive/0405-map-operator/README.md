# 0405 — Map Operator

Implement a map operator that transforms each emitted value, applying x => x*2 to a stream of 1, 2, 3, 4. With no closures in C, the operator threads its transform and downstream sink through function pointers.

## Run

    make -s && ./mapoperator
