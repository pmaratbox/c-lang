# 0036 — Inheritance & Overriding

Define a base `Animal` with a `speak` method, a `Dog` that overrides it, and call both, printing `animal: some sound` and `dog: Woof`. C has no objects or inheritance; virtual methods are simulated by hand. Each `struct Animal` holds a function pointer for `speak`, and giving `dog` a different pointer is the "override" — exactly the vtable mechanism C++ generates automatically.

## Run

    make && ./inheritance
