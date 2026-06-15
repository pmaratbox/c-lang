#include <sqlite3.h>
#include <stdio.h>

int main(void) {
  sqlite3 *db;
  sqlite3_open(":memory:", &db);

  sqlite3_stmt *q;
  sqlite3_prepare_v2(db, "select 42", -1, &q, 0);
  while (sqlite3_step(q) == SQLITE_ROW)
    printf("%d\n", sqlite3_column_int(q, 0));
  sqlite3_finalize(q);

  sqlite3_close(db);
  return 0;
}
