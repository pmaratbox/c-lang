# 0115 — Dispatch Table

Store functions in a map keyed by name, then apply "add" and "mul" to (3,4), printing `7 12`. An array of name/function-pointer entries is searched by `strcmp` to dispatch the call.

## Run

    make && ./table
