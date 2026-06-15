# 0441 — Aggregate functions

Creates an in-memory SQLite database with the C `<sqlite3.h>` API, inserts five amounts (10, 20, 30, 40, 50) into a table using a prepared statement, then runs `select count(*), sum(amount), min(amount), max(amount) from t` and prints the four aggregate values, each on its own line, via `sqlite3_column_int`.

## Run

    make && ./aggregate-functions
