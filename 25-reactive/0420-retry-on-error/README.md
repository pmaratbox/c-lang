# 0420 — Retry On Error

Implement retry(n) that resubscribes to the source on error up to n times; the source succeeds on the 3rd subscription. In C, observers are structs of function pointers and retry simply re-invokes the source's subscribe routine on error.

## Run

    make -s && ./retryonerror
