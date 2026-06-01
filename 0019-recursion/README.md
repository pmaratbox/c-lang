# 0019 — Recursion

Define a recursive `factorial(n)` that multiplies `n` by `factorial(n - 1)` until it bottoms out at `1`, then print `factorial(5) = 120`. The multiplication happens after `factorial(n - 1)` returns, so the call is not in tail position and depth is bounded by the stack regardless of optimization level. `long` is only guaranteed to be at least 32 bits — 64 bits on this platform — but `factorial` overflows any fixed-width integer quickly (`int` already by `13!`), so a wider type only buys headroom.

## Run

    make && ./recursion
