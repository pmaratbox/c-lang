#include <sqlite3.h>
#include <stdio.h>
int main(void){
  sqlite3 *db; sqlite3_open(":memory:", &db);
  sqlite3_exec(db,"create table sales(category text, amount integer)",0,0,0);
  const char *cats[]={"a","b","a","b","a"};
  const int amts[]={10,20,30,5,2};
  sqlite3_stmt *ins; sqlite3_prepare_v2(db,"insert into sales values(?,?)",-1,&ins,0);
  for(int i=0;i<5;i++){ sqlite3_bind_text(ins,1,cats[i],-1,SQLITE_TRANSIENT); sqlite3_bind_int(ins,2,amts[i]);
    sqlite3_step(ins); sqlite3_reset(ins); }
  sqlite3_finalize(ins);
  sqlite3_stmt *q; sqlite3_prepare_v2(db,"select category,sum(amount) from sales group by category order by category",-1,&q,0);
  while(sqlite3_step(q)==SQLITE_ROW)
    printf("%s %d\n", sqlite3_column_text(q,0), sqlite3_column_int(q,1));
  sqlite3_finalize(q);
  sqlite3_close(db);
  return 0;
}
