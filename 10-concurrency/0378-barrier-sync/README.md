# 0378 — Barrier Synchronization

Have 3 threads each arrive at a barrier before any proceeds, then print `all reached: 3`. In C a mutex plus condition variable releases all waiters once the arrival count is met.

## Run

    make && ./barriersync
