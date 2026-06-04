# 0382 — Fork-Join Sum

Recursively fork the sum of [1..8] into halves and join the partial sums, printing `36`. In C each recursion forks one half onto a new thread and joins it.

## Run

    make && ./forkjoinsum
