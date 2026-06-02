# 0073 — Caesar Cipher

Encrypt `abc` with a Caesar cipher shifting each letter forward by `1` (wrapping within the alphabet) and print the result: `bcd`. `char`s are small integers: `text[i] - 'a'` gives `0..25`, and `% 26` wraps the shift before adding `'a'` back.

## Run

    make && ./caesar
