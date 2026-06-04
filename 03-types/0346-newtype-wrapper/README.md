# 0346 — Newtype Wrapper

Wrap raw integers in distinct UserId and ProductId types so they cannot be confused, printing `user-1 prod-2`. Wrapping each int in its own single-field `struct` makes the two types non-interchangeable.

## Run

    make && ./newtypewrapper
