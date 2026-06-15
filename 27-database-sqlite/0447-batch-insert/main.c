#include <sqlite3.h>
#include <stdio.h>

int main(void){
  sqlite3 *db; sqlite3_open(":memory:", &db);
  sqlite3_exec(db,"create table t(n integer)",0,0,0);

  /* batch insert 1..1000 with one prepared statement inside a transaction */
  sqlite3_exec(db,"begin",0,0,0);
  sqlite3_stmt *ins; sqlite3_prepare_v2(db,"insert into t(n) values(?)",-1,&ins,0);
  for(int i=1;i<=1000;i++){
    sqlite3_bind_int(ins,1,i);
    sqlite3_step(ins);
    sqlite3_reset(ins);
  }
  sqlite3_finalize(ins);
  sqlite3_exec(db,"commit",0,0,0);

  sqlite3_stmt *q; sqlite3_prepare_v2(db,"select count(*) from t",-1,&q,0);
  while(sqlite3_step(q)==SQLITE_ROW)
    printf("%d\n", sqlite3_column_int(q,0));
  sqlite3_finalize(q);
  sqlite3_close(db);
  return 0;
}
