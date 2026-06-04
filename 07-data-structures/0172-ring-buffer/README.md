# 0172 — Ring Buffer

Push 1,2,3,4,5 into a fixed capacity-3 ring buffer (overwriting oldest) and print the final contents `3 4 5`. Modular `head`/`count` indices wrap around a fixed array so writes past capacity overwrite the oldest slot.

## Run

    make && ./buffer
