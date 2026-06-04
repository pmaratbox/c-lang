# 0380 — Compare-And-Swap Loop

Increment a shared value to 100 using a CAS retry loop from multiple threads, printing `100`. C's `<stdatomic.h>` provides `atomic_compare_exchange_weak` for the lock-free retry.

## Run

    make && ./compareandswap
