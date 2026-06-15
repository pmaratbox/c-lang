# 0445 — Transactions

Creates a `t(n integer)` table in an in-memory SQLite database and exercises
the driver's real transaction control via the C `<sqlite3.h>` API. A first
transaction inserts `1` and `2` and `COMMIT`s them; a second transaction
inserts `3` and `ROLLBACK`s it, so that row is discarded. The surviving rows
are read back with `select n from t order by n` and printed one per line,
showing only `1` and `2`.

## Run

    make && ./transaction-commit-rollback
