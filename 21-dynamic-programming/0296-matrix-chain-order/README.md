# 0296 — Matrix Chain Order

Find the minimum scalar multiplications to multiply matrices with dimensions [10,20,30,40], printing `18000`. An interval `dp[i][j]` table over split points `k`, seeded with `INT_MAX`, is the idiomatic C approach.

## Run

    make && ./matrixchainorder
