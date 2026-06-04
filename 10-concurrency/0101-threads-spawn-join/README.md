# 0101 — Threads: Spawn and Join

Spawn 3 worker threads, wait for all of them to finish, then print `done: 3`. In C this uses POSIX `pthread_create` and `pthread_join`.

## Run

    make && ./spawnjoin
