# 0328 — Trampoline

Sum 1..100 with a trampolined recursion that avoids deep stacks, printing `5050`. Each step returns a thunk struct carrying the next state, and a flat driver loop bounces it until done.

## Run

    make && ./trampoline
