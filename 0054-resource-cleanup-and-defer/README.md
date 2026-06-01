# 0054 — Resource Cleanup & Defer

Acquire a resource, use it, and let the language release it automatically at scope exit, printing `open`, `use`, and `close` in that order. C has no destructors, `defer`, or `finally`: you release the resource explicitly. The classic idiom funnels every exit path after acquisition through one `cleanup:` label with `goto cleanup;`, so `release()` runs exactly once.

## Run

    make && ./cleanup
