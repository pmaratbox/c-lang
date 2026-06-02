# 0033 — Custom Error Types

Define a custom error, raise it from a `check` that rejects values over `100`, catch it for the input `200`, and print `error: value too large`. C has no exceptions; the convention is to return a status code (here an `enum`) and let the caller branch on it. Richer schemes set a global `errno` or return a sentinel like `NULL`/`-1`.

## Run

    make && ./errors
