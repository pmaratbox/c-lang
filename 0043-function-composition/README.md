# 0043 — Function Composition

Compose `inc` (add one) and `twice` (multiply by two) into one function and apply it to `3`, so `inc(twice(3))` prints `7`. C has no closures, so a composed function cannot capture `f` and `g` and be returned. The equivalent applies the composition directly: `compose(f, g, x)` takes both function pointers and the argument, returning `f(g(x))`.

## Run

    make && ./compose
