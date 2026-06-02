# 0061 — Reverse a String

Reverse the string `abc` character by character and print the result: `cba`. Bytes are swapped in place with a two-pointer loop — correct for ASCII, but it would corrupt a multi-byte UTF-8 string since it reverses bytes, not characters.

## Run

    make && ./reverse
