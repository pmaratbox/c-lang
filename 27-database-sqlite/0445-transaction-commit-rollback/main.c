#include <sqlite3.h>
#include <stdio.h>

int main(void){
  sqlite3 *db; sqlite3_open(":memory:", &db);
  sqlite3_exec(db,"create table t(n integer)",0,0,0);

  /* first transaction: insert 1 and 2, then commit */
  sqlite3_exec(db,"begin",0,0,0);
  sqlite3_exec(db,"insert into t(n) values(1)",0,0,0);
  sqlite3_exec(db,"insert into t(n) values(2)",0,0,0);
  sqlite3_exec(db,"commit",0,0,0);

  /* second transaction: insert 3, then roll back */
  sqlite3_exec(db,"begin",0,0,0);
  sqlite3_exec(db,"insert into t(n) values(3)",0,0,0);
  sqlite3_exec(db,"rollback",0,0,0);

  sqlite3_stmt *q; sqlite3_prepare_v2(db,"select n from t order by n",-1,&q,0);
  while(sqlite3_step(q)==SQLITE_ROW)
    printf("%d\n", sqlite3_column_int(q,0));
  sqlite3_finalize(q);
  sqlite3_close(db);
  return 0;
}
