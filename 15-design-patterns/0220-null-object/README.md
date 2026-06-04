# 0220 — Null Object

Compare a no-op null logger with a real logger; only the real one records, so print the logged count `1`. Both loggers share a struct with a log() function pointer, but the null variant's function does nothing.

## Run

    make && ./nullobject
