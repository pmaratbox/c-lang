# 0057 — Sieve of Eratosthenes

Use the Sieve of Eratosthenes to find every prime number up to `10` and print them: `2 3 5 7`. A fixed `bool[11]` (from `<stdbool.h>`) holds the flags; multiples are struck from `i*i`, and the guard `i*i <= n` avoids a separate square-root call.

## Run

    make && ./sieve
