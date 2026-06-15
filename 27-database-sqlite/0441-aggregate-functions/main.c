#include <sqlite3.h>
#include <stdio.h>

int main(void) {
  sqlite3 *db;
  sqlite3_open(":memory:", &db);

  sqlite3_exec(db, "create table t(amount integer)", 0, 0, 0);

  int amounts[] = {10, 20, 30, 40, 50};
  sqlite3_stmt *ins;
  sqlite3_prepare_v2(db, "insert into t values(?)", -1, &ins, 0);
  for (int i = 0; i < 5; i++) {
    sqlite3_bind_int(ins, 1, amounts[i]);
    sqlite3_step(ins);
    sqlite3_reset(ins);
  }
  sqlite3_finalize(ins);

  sqlite3_stmt *q;
  sqlite3_prepare_v2(db,
      "select count(*), sum(amount), min(amount), max(amount) from t",
      -1, &q, 0);
  while (sqlite3_step(q) == SQLITE_ROW) {
    printf("%d\n", sqlite3_column_int(q, 0));
    printf("%d\n", sqlite3_column_int(q, 1));
    printf("%d\n", sqlite3_column_int(q, 2));
    printf("%d\n", sqlite3_column_int(q, 3));
  }
  sqlite3_finalize(q);

  sqlite3_close(db);
  return 0;
}
