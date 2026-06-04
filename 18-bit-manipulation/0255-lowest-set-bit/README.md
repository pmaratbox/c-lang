# 0255 — Lowest Set Bit

Isolate the lowest set bit of 12 (1100), printing `4`. On an `unsigned` value `x & (~x + 1)` masks off all but the lowest set bit.

## Run

    make && ./lowestsetbit
