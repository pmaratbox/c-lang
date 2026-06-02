# 0021 — Mutability & References

Have a function increment a value in place — through a pointer, reference, or mutable holder — so the caller sees it change from `before: 1` to `after: 2`. Passing `&n` gives the function a pointer (`int *`); `(*p)++` increments the pointed-to `int`, so the change is visible in `main`. C is strictly pass-by-value — without the pointer the function would modify only a local copy.

## Run

    make && ./references
