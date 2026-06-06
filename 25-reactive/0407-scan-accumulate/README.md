# 0407 — Scan (Running Fold)

Implement a scan operator that emits the running accumulation; produce the running sums of 1, 2, 3, 4. The observer is a function pointer plus an opaque context, so scan threads its accumulator through a small state struct.

## Run

    make -s && ./scanaccumulate
