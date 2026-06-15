# 0446 — Indexes

Creates an in-memory SQLite database with the C `<sqlite3.h>` API, inserts three rows into a `products` table via a prepared statement (`sqlite3_prepare_v2` / `sqlite3_bind_int` / `sqlite3_bind_text`), then executes `create index idx_sku on products(sku)` with `sqlite3_exec` to build a real index. It runs a parameterized lookup `select price from products where sku=?` bound to `'B'` and prints the matching price with `sqlite3_column_int`.

## Run

    make && ./indexes
