# 0104 — Atomic Counter

Increment a shared atomic counter from multiple threads 1000 times total without a lock, printing `1000`. In C `<stdatomic.h>` provides `atomic_int` and `atomic_fetch_add`.

## Run

    make && ./counter
