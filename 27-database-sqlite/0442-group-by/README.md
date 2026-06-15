# 0442 — Group by

Creates an in-memory SQLite database with the C `<sqlite3.h>` API, inserts sales rows via a prepared statement (`sqlite3_prepare_v2` / `sqlite3_bind_text` / `sqlite3_bind_int`), then aggregates amounts per category with `select category,sum(amount) from sales group by category order by category`, printing each group as `category sum`.

## Run

    make && ./group-by
