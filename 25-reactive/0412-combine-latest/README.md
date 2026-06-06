# 0412 — Combine Latest

Implement combineLatest of two timed streams, emitting the pair of latest values whenever either source emits (once both have emitted). A fixed-size event array acts as the virtual-time priority queue, scanned for the smallest (time, seq) on each step.

## Run

    make -s && ./combinelatest
