# 0105 — Channels / Message Passing

Send the values 1, 2, 3 through a channel (or queue) from one thread and receive them in order, printing `1 2 3`. C has no built-in channel, so a mutex plus condition variable backs a small ring-buffer queue.

## Run

    make && ./messagepassing
