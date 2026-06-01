# 0052 — Queues

Enqueue `1`, `2`, and `3` into a queue, then dequeue them all and print them in first-in-first-out order: `1 2 3`. C has no queue; a fixed array with `head` and `tail` indices is the classic queue — `tail` advances on enqueue, `head` on dequeue (a ring buffer wraps these indices).

## Run

    make && ./queues
