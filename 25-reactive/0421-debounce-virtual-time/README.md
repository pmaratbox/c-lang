# 0421 — Debounce (Virtual Time)

Implement debounce(window) on a virtual-time scheduler: emit a value only after a quiet gap of `window` ticks with no newer value. In C the scheduler is a fixed array of tasks scanned for the smallest (time, seq), and a cancel just flips a `dead` flag.

## Run

    make -s && ./debouncevirtualtime
