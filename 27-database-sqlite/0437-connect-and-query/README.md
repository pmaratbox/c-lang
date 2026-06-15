# 0437 — Connect & query

Opens an in-memory SQLite database with `sqlite3_open(":memory:")` from the C `<sqlite3.h>` API, runs the query `select 42` via a prepared statement (`sqlite3_prepare_v2` / `sqlite3_step`), and prints the single integer result with `sqlite3_column_int`.

## Run

    make && ./connect-and-query
