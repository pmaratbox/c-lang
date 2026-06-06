# 0410 — Merge Streams

Implement merge of two timed streams using a virtual-time scheduler, interleaving them by emission time. A small fixed (time, seq, callback) array popped in order keeps the merge fully deterministic without threads or real timers.

## Run

    make -s && ./mergestreams
