# 0205 — Decorator

Decorate a base coffee (cost 2) with milk (+1) and sugar (+1), printing the total cost `4`. Each decorator is a struct holding a function pointer and an inner component, recursing into the wrapped cost().

## Run

    make && ./decorator
