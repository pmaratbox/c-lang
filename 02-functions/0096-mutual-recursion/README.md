# 0096 — Mutual Recursion

Using two mutually recursive functions `isEven` and `isOdd` (each calling the other), report whether `4` and `3` are even, printing `even` and `odd`. C resolves names top to bottom, so `is_odd` needs a forward declaration before `is_even` can call it.

## Run

    make && ./mutual
