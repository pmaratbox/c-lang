# 0074 — Run-Length Encoding

Run-length encode the string `aaabbc` (each run of a repeated character becomes the character followed by its count), printing `a3b2c1`. The inner loop advances over a run of identical bytes; `printf` with the `%c%d` verbs prints the character and its count directly.

## Run

    make && ./rle
