# 0439 — Parameterized query

Bind a value to a SQL placeholder safely instead of building the query by string concatenation. Using the C SQLite driver (`<sqlite3.h>`), this builds an in-memory database, inserts three users, then prepares `select name from users where id=?` and binds the integer `2` with `sqlite3_bind_int` before stepping the result and printing the matching name.

## Run

    make && ./parameterized-query
