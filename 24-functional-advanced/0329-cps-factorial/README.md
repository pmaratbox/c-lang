# 0329 — CPS Factorial

Compute 5! in continuation-passing style, printing `120`. C lacks closures, so the continuation is threaded as an accumulated integer applied by the base case.

## Run

    make && ./cpsfactorial
