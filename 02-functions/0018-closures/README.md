# 0018 — Closures

Build a counter that captures a private count starting at zero; each call to the returned function increments the count and returns it, so calling it twice prints 1 then 2. C has no closures — a function cannot capture surrounding state — so the state is made explicit: a `Counter` struct holds the `count`, and `next` takes a pointer to it. The caller threads the struct through each call by hand, doing manually what a closure would capture automatically.

## Run

    make && ./closures
