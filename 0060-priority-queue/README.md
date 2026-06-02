# 0060 — Priority Queue

Push `3`, `1`, and `2` into a min-priority-queue, then pop them all and print them in priority (ascending) order: `1 2 3`. C has no priority queue; this is an array-backed one — `push` shifts elements to insert in sorted order, so `pop` takes the minimum from the front. A binary heap is the efficient version.

## Run

    make && ./priorityqueue
