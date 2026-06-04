# 0118 — Option Map Chaining

Map a function over a present optional (10 -> 12) and an absent one (-> fallback), printing `12 none`. An `Option` struct carries a present flag, and `map_opt` transforms the value only when it is present.

## Run

    make && ./mapchain
