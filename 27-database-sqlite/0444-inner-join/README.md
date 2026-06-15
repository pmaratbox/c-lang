# 0444 — Inner join

Creates an in-memory SQLite database with the C `<sqlite3.h>` API, fills a `users` and an `orders` table via prepared statements (`sqlite3_prepare_v2` / `sqlite3_bind_int` / `sqlite3_bind_text`), then joins them on the user key with `select u.name,o.item from orders o join users u on u.id=o.user_id order by u.name,o.item`, printing each matched row as `name item`.

## Run

    make && ./inner-join
