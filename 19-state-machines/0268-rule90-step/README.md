# 0268 — Cellular Automaton Rule 90

Apply one Rule 90 step (new = left XOR right) to the row "00100" with zero boundaries, printing `01010`. In C, the `^` operator on the neighbor bits gives Rule 90 directly.

## Run

    make && ./rule90step
