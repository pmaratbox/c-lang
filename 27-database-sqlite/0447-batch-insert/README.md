# 0447 — Batch insert

Creates a `t(n integer)` table in an in-memory SQLite database and inserts
1000 rows (values `1..1000`) efficiently using a single prepared statement
(`sqlite3_prepare_v2` with `sqlite3_bind_int`/`sqlite3_step`/`sqlite3_reset`)
wrapped in one transaction via the C `<sqlite3.h>` API. It then runs
`select count(*) from t` and prints the resulting count, `1000`.

## Run

    make && ./batch-insert
