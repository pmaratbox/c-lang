# 0196 — Error Wrapping

Wrap an inner error "inner" inside an outer context and print the combined message `outer: inner`. C has no error type, so build the wrapped message by concatenating the outer context with the inner cause.

## Run

    make && ./wrapping
