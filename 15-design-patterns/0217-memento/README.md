# 0217 — Memento

Save state 1, change it to 2, then restore from the memento, printing current then restored `2 1`. A Memento struct captures the originator's state by value so restore() can roll it back.

## Run

    make && ./memento
