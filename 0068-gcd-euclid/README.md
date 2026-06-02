# 0068 — GCD (Euclid)

Compute the greatest common divisor of `48` and `36` with Euclid's algorithm (repeatedly replace the pair with `(b, a % b)` until the remainder is zero) and print it: `12`. A temporary `t` holds `b` while the pair advances to `(b, a % b)` each iteration until `b` is zero.

## Run

    make && ./gcd
