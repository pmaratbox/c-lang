# 0250 — Iterative Fast Power

Compute 2^10 by iterative binary exponentiation, printing `1024`. In C we square the base while right-shifting the exponent, multiplying in when the low bit is set.

## Run

    make && ./fastpoweriterative
