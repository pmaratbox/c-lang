# 0110 — Currying

Curry a two-argument add into a chain of one-argument functions and call it as `add(2)(3)`, printing `5`. C lacks closures, so `add` returns a struct capturing the first argument that a later `apply` consumes.

## Run

    make && ./currying
