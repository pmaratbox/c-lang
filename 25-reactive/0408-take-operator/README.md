# 0408 — Take Operator

Implement take(n) over an unbounded source of the natural numbers, emitting the first 3 then completing (and unsubscribing the source). In C the observer is a struct of function pointers plus a context pointer, and unsubscribing just clears an `active` flag the source loop checks.

## Run

    make -s && ./takeoperator
