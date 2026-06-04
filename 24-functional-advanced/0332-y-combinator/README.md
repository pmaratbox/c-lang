# 0332 — Y Combinator

Define factorial via a fixed-point combinator (no named self-recursion) and compute 5!, printing `120`. Without closures, `fix` hands the non-recursive generator a self-reference function pointer it re-invokes to reach the fixed point.

## Run

    make && ./ycombinator
