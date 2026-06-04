# 0391 — URL Percent-Encode

Percent-encode the string "a b&c" to `a%20b%26c`. Unreserved chars pass through; others become `%` plus uppercase hex via `%02X`.

## Run

    make && ./urlencode
