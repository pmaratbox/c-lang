# 0039 — Records & Value Equality

Create two points with the same fields, print one as `point: (1, 2)`, and compare them by value to print `equal: yes`. C has no value equality for structs — `==` doesn't apply — so the fields are compared individually. `memcmp` can compare the bytes, but struct padding makes that unreliable in general.

## Run

    make && ./records
