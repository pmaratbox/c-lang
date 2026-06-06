# 0424 — Signal + Computed

Implement fine-grained reactivity: a writable signal and a derived computed that recomputes when its dependency changes. In C a signal is a struct holding a value and a fixed array of function-pointer subscribers, and the computed registers its recompute callback there.

## Run

    make -s && ./reactivesignalcomputed
