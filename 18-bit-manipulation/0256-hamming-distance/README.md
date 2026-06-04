# 0256 — Hamming Distance

Compute the bit Hamming distance between 1 and 4, printing `2`. Counting set bits of the XOR via Kernighan's `x &= x - 1` loop gives the distance.

## Run

    make && ./hammingdistance
