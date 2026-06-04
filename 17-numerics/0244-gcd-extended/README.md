# 0244 — Extended Euclid

Compute extended gcd(30,12) returning g and Bezout coefficients, printing `6 1 -2` (since 30*1+12*(-2)=6). In C we recurse, threading the Bezout coefficients back through pointer out-params.

## Run

    make && ./gcdextended
