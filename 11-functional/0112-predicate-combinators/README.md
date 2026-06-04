# 0112 — Predicate Combinators

Combine predicates with AND/OR/NOT: test `isEven AND isPositive` on 4 (yes) and -4 (no), printing `yes no`. Predicates are function pointers, and `and_pred` combines two into their conjunction.

## Run

    make && ./combinators
