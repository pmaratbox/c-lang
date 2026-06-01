# 0022 — Concurrency

Start two tasks that produce `1` and `2`, let them run concurrently, then join their results and print `sum: 3`. POSIX threads: `pthread_create` starts each thread on `task`, and `pthread_join` waits and collects its `void *` return. Each thread is handed a pointer to its own `int`, so there is no shared state to guard. Building needs `-pthread`.

## Run

    make && ./concurrency
