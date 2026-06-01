# 0020 — Pattern Matching

Match `n` against the literal patterns `1` and `2` with a wildcard fallback, mapping `1`, `2`, and `5` to `one`, `two`, and `many`. C's `switch` falls through from one `case` to the next unless you `break` or `return`; each arm here `return`s, so control never falls through. The controlling expression must be an integer type, and `default` catches unlisted values.

## Run

    make && ./matching
