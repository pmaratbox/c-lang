# 0422 — Throttle (Virtual Time)

Implement throttle(window) (leading edge) on a virtual-time scheduler: emit a value, then suppress further values for `window` ticks. In C the scheduler is a fixed array of (time, seq) events scanned for the smallest key, so no heap or real timers are needed.

## Run

    make -s && ./throttlevirtualtime
