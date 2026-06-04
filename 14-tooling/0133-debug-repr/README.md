# 0133 — Debug Representation

Produce a debug/structured representation of a Point(1,2) and print `Point(x=1, y=2)`. C has no derived debug formatting, so a small `snprintf`-based helper builds the representation.

## Run

    make && ./repr
