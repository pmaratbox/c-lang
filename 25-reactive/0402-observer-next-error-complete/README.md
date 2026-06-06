# 0402 — Observer Contract

Demonstrate the observer contract next*-then-terminal: emit 1 and 2, complete, and show that a post-complete next is ignored. A small struct holds a `stopped` flag that the wrapped next/complete functions check before acting.

## Run

    make -s && ./observernexterrorcomplete
