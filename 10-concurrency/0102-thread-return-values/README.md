# 0102 — Threads Returning Values

Run two threads that compute the squares of 3 and 4, join them, and print the sum of their results `25`. In C a thread "returns" by passing a pointer through `pthread_join`.

## Run

    make && ./returnvalues
