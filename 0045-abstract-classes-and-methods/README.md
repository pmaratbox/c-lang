# 0045 — Abstract Classes & Methods

Define an abstract `Shape` with an abstract `area` and a concrete `describe` that uses it, then implement a `Square` of side 3 and print `area: 9`. C has neither classes nor abstraction; a `struct` holding a function pointer is the manual vtable. The pointer is the "abstract" method each instance must set, and `describe` is a function that calls through it.

## Run

    make && ./shapes
