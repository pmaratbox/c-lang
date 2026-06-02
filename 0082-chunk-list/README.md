# 0082 — Chunk a List

Split the list `1, 2, 3, 4, 5, 6, 7` into chunks of `3` and print each chunk on its own line: `1 2 3`, `4 5 6`, `7`. An outer loop steps by `size`; the inner loop prints up to `size` elements, bounded by `n` so the last chunk is short.

## Run

    make && ./chunk
