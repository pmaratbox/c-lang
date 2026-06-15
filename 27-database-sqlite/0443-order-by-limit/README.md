# 0443 — Order by & limit

Creates an in-memory SQLite database with the C `<sqlite3.h>` API, inserts six integers into a `scores` table via a prepared statement (`sqlite3_prepare_v2` / `sqlite3_bind_int`), then runs `select value from scores order by value desc limit 3` to sort descending and take the top three rows, printing each value on its own line with `sqlite3_column_int`.

## Run

    make && ./order-by-limit
