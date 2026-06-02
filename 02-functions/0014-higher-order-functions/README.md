# 0014 — Higher-Order Functions

Write `apply(f, x)` that calls the function `f` on `x`, then pass it two
different functions, `inc` and `double`. C passes functions as **function
pointers** — the parameter `int (*f)(int)` points to a function taking and
returning `int`. (The doubling function is `dbl` because `double` is a reserved
type keyword.)

## Run

    make && ./hof
