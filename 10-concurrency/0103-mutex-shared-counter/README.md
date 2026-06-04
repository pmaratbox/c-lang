# 0103 — Mutex-Protected Counter

Have multiple threads each increment a shared counter under a mutex so the total is exactly `1000`. In C a `pthread_mutex_t` guards the shared variable around each increment.

## Run

    make && ./sharedcounter
