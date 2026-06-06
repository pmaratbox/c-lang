# 0411 — Concat Streams

Implement concat: subscribe to the second source only after the first completes; concat [1,2] then [3,4]. In C an observer is a struct of `next`/`complete` function pointers plus a context, and concat chains subscriptions via the first source's complete callback.

## Run

    make -s && ./concatstreams
