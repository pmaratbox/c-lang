# 0409 — Distinct Until Changed

Implement distinctUntilChanged, dropping consecutive duplicate values from 1,1,2,2,2,3,1. The C version tracks the last forwarded value in a small struct and emits only when the new value differs.

## Run

    make -s && ./distinctuntilchanged
