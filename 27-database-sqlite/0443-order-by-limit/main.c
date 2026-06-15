#include <sqlite3.h>
#include <stdio.h>
int main(void){
  sqlite3 *db; sqlite3_open(":memory:", &db);
  sqlite3_exec(db,"create table scores(value integer)",0,0,0);
  const int vals[]={50,90,70,30,100,20};
  sqlite3_stmt *ins; sqlite3_prepare_v2(db,"insert into scores values(?)",-1,&ins,0);
  for(int i=0;i<6;i++){ sqlite3_bind_int(ins,1,vals[i]); sqlite3_step(ins); sqlite3_reset(ins); }
  sqlite3_finalize(ins);
  sqlite3_stmt *q; sqlite3_prepare_v2(db,"select value from scores order by value desc limit 3",-1,&q,0);
  while(sqlite3_step(q)==SQLITE_ROW)
    printf("%d\n", sqlite3_column_int(q,0));
  sqlite3_finalize(q);
  sqlite3_close(db);
  return 0;
}
