# 0015 — Interfaces

Define a `Shape` interface with `name()` and `area()` methods, implement it for a rectangle and a square, then loop over a collection of shapes and print each one's area. C has no built-in polymorphism, so the "interface" is built by hand: a struct holds *function pointers* (`name`, `area`) alongside the shape's data, and each shape is initialized with the functions for its type — a hand-rolled vtable. Calling `s->area(s)` passes the object back to its own function as `self`, which is exactly the dynamic dispatch other languages generate for you.

## Run

    make && ./interfaces
