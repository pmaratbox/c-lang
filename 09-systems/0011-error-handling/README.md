# 0011 — Error Handling

Write a `divide(a, b)` that reports a zero divisor, then call it on `10 / 2`
(prints the result) and `10 / 0` (prints an error). C has no exceptions: the
common convention is to return a status code (`0` ok, non-zero on error) and
pass the result back through a pointer parameter.

## Run

    make && ./error_handling
