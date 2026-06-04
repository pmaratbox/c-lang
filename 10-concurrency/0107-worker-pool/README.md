# 0107 — Worker Pool

Distribute squaring of 1..4 across a pool of workers, collect the results, and print them sorted ascending `1 4 9 16`. In C each worker writes into its own task slot, then results are sorted before printing.

## Run

    make && ./pool
