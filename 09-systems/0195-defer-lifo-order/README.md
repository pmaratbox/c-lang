# 0195 — Defer LIFO Order

Register three deferred actions printing 1, 2, 3 and show they run in last-in-first-out order `3 2 1`. C lacks defer, so emulate it with an explicit stack popped in reverse.

## Run

    make && ./lifoorder
