# 0109 — Run-Once Initialization

Ensure an initializer runs exactly once even when several threads race to trigger it, printing `init count: 1`. In C `pthread_once` with a `PTHREAD_ONCE_INIT` control runs the init body a single time.

## Run

    make && ./onceinit
