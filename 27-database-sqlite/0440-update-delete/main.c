#include <sqlite3.h>
#include <stdio.h>

int main(void) {
  sqlite3 *db;
  sqlite3_open(":memory:", &db);
  sqlite3_exec(db, "create table users(id integer, name text)", 0, 0, 0);

  const char *names[] = {"alice", "bob", "carol"};
  sqlite3_stmt *ins;
  sqlite3_prepare_v2(db, "insert into users values(?,?)", -1, &ins, 0);
  for (int i = 0; i < 3; i++) {
    sqlite3_bind_int(ins, 1, i + 1);
    sqlite3_bind_text(ins, 2, names[i], -1, SQLITE_TRANSIENT);
    sqlite3_step(ins);
    sqlite3_reset(ins);
  }
  sqlite3_finalize(ins);

  sqlite3_exec(db, "update users set name='robert' where id=2", 0, 0, 0);
  sqlite3_exec(db, "delete from users where id=1", 0, 0, 0);

  sqlite3_stmt *q;
  sqlite3_prepare_v2(db, "select id,name from users order by id", -1, &q, 0);
  while (sqlite3_step(q) == SQLITE_ROW)
    printf("%d %s\n", sqlite3_column_int(q, 0),
           (const char *)sqlite3_column_text(q, 1));
  sqlite3_finalize(q);

  sqlite3_close(db);
  return 0;
}
