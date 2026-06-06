# 0419 — Catch Error

Implement catchError that, on an error from the source, switches to a fallback stream. In C the observer is a struct of function pointers plus a `ctx` void pointer, so the error callback simply drives the fallback into the downstream sink.

## Run

    make -s && ./catcherror
