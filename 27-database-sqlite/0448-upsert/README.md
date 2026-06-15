# 0448 — Upsert

Creates an in-memory SQLite database with the C `<sqlite3.h>` API and a `inv(item text primary key, qty integer)` table seeded with `('apple',5)`. It then runs an UPSERT with a prepared statement using real SQL `insert into inv values(?,?) on conflict(item) do update set qty=qty+excluded.qty`: re-inserting `apple` with qty 5 hits the primary-key conflict and updates it to 10, while `banana` with qty 3 inserts a new row. Finally it runs `select item,qty from inv order by item` and prints each row as `item qty` via `sqlite3_column_text` / `sqlite3_column_int`.

## Run

    make && ./upsert
