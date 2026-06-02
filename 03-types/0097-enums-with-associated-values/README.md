# 0097 — Enums with Associated Values

Define a shape type carrying associated data — `Rect(2, 3)` and `Square(4)` — compute each area by matching on the variant, and print `6` and `16`. A tagged union — an `enum kind` plus a `union` of the per-variant data — is C's manual sum type; the `kind` selects which union member is valid.

## Run

    make && ./shapes
