# 0330 — Lens Get/Set

Use a lens over the nested value {a:{b:1}} to get b (1) and to set b to 2, printing `1 2`. The lens is a getter plus a setter that returns a copy by value, leaving the original struct untouched.

## Run

    make && ./lensgetset
