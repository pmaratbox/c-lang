# 0206 — Facade

Expose a single facade call that starts three subsystems and reports `ready`. A facade_start() function sequences three static subsystem init functions, then returns the status string.

## Run

    make && ./facade
