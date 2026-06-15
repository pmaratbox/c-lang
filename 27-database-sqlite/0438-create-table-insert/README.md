# 0438 — Create table & insert

This lesson uses the real SQLite C API (`<sqlite3.h>`) against an in-memory database. It creates a `users(id integer, name text)` table, inserts three rows with a prepared statement and bound parameters, then runs `select name from users order by id` and prints each name on its own line.

## Run

    make && ./create-table-insert
