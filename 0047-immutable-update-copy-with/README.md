# 0047 — Immutable Update (Copy-with)

Make a copy of the point `(1, 2)` with its `x` changed to `9`, leaving the original intact, and print `original: (1, 2)` then `updated: (9, 2)`. C structs are value types: `struct Point p2 = p1;` copies all fields, so changing `p2.x` leaves `p1` untouched. Assignment is the whole mechanism — there is no field-update helper.

## Run

    make && ./immutable
