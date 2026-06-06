# 0401 — Create an Observable

Build a push-based Observable from scratch that emits 1, 2, 3 to its observer and then completes. In C the observer is a struct of function pointers (next/complete) and the Observable is a plain function that calls them.

## Run

    make -s && ./observablecreate
