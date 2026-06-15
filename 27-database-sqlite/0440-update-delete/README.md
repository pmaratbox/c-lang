# 0440 — Update & delete

Seeds a `users` table in an in-memory SQLite database, then runs an `UPDATE`
to rename one row and a `DELETE` to remove another using the C `<sqlite3.h>`
API (`sqlite3_exec` for the DDL/DML, prepared statements with parameter
binding for inserts and the final `SELECT`). The remaining rows are read back
with `ORDER BY id` and printed as space-separated `id name` pairs.

## Run

    make && ./update-delete
