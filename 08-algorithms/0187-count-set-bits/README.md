# 0187 — Count Set Bits

Count the set bits (popcount) of 13 and print `3`. 13 = 1101 -> 3 ones, cleared one at a time with `n &= n - 1`.

## Run

    make && ./setbits
