# 0139 — Recursive Power

Compute 2 raised to the 10th power recursively and print `1024`. In C a tail of `base * power(base, exp - 1)` builds the result on the call stack.

## Run

    make && ./power
