# 0414 — FlatMap (mergeMap)

Implement flatMap/mergeMap: map each outer value to an inner timed stream and merge all inners concurrently (no cancellation). A fixed `Event` array sorted by `(time, seq)` acts as the virtual-time scheduler, so the push-based observable is fully deterministic.

## Run

    make -s && ./flatmapstreams
