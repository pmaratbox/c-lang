# 0349 — Trait Composition

Compose two capabilities (A printing "a", B printing "b") into one type and invoke both, printing `a b`. In C, composition is achieved by embedding two function-pointer structs into one aggregate.

## Run

    make && ./traitcomposition
