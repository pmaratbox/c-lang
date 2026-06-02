# 0098 — Memoization

Compute `fibonacci(10)` recursively with memoization (caching each result so it is computed once) and print it: `55`. Fixed arrays act as the cache: `computed[n]` flags whether `cache[n]` holds a result yet (arrays zero-initialize at file scope).

## Run

    make && ./memo
