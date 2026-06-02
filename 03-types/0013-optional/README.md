# 0013 — Optional

Hold one value that is present (`42`) and one that is absent, then print each
with a fallback of `-1` when absent. C has no Option type — a pointer (`int *`)
is the usual stand-in, with `NULL` meaning absent. The helper returns `*p` or
the fallback.

## Run

    make && ./optional
