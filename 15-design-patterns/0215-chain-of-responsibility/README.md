# 0215 — Chain of Responsibility

Pass a request of level 2 along a handler chain so the level-2 handler handles it, printing `handled by 2`. Handlers are linked by a next pointer, each forwarding the request until one matches.

## Run

    make && ./chainofresponsibility
