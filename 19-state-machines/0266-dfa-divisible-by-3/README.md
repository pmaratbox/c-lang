# 0266 — DFA: Divisible by 3

Use a 3-state DFA over binary input to test whether "110" (6, yes) and "100" (4, no) are divisible by 3, printing `yes no`. In C, the state is just `value % 3` updated as you scan each bit.

## Run

    make && ./dfadivisibleby3
