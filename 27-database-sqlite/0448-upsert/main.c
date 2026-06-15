#include <sqlite3.h>
#include <stdio.h>
int main(void){
  sqlite3 *db; sqlite3_open(":memory:", &db);
  sqlite3_exec(db,"create table inv(item text primary key, qty integer)",0,0,0);
  sqlite3_exec(db,"insert into inv values('apple',5)",0,0,0);
  const char *items[]={"apple","banana"};
  const int qtys[]={5,3};
  sqlite3_stmt *up; sqlite3_prepare_v2(db,
    "insert into inv values(?,?) on conflict(item) do update set qty=qty+excluded.qty",
    -1,&up,0);
  for(int i=0;i<2;i++){ sqlite3_bind_text(up,1,items[i],-1,SQLITE_TRANSIENT);
    sqlite3_bind_int(up,2,qtys[i]); sqlite3_step(up); sqlite3_reset(up); }
  sqlite3_finalize(up);
  sqlite3_stmt *q; sqlite3_prepare_v2(db,"select item,qty from inv order by item",-1,&q,0);
  while(sqlite3_step(q)==SQLITE_ROW)
    printf("%s %d\n", sqlite3_column_text(q,0), sqlite3_column_int(q,1));
  sqlite3_finalize(q);
  sqlite3_close(db);
  return 0;
}
