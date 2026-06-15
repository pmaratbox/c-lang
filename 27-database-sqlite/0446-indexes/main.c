#include <sqlite3.h>
#include <stdio.h>
int main(void){
  sqlite3 *db; sqlite3_open(":memory:", &db);
  sqlite3_exec(db,"create table products(id integer, sku text, price integer)",0,0,0);
  const char *skus[]={"A","B","C"};
  const int prices[]={100,200,300};
  sqlite3_stmt *ins; sqlite3_prepare_v2(db,"insert into products values(?,?,?)",-1,&ins,0);
  for(int i=0;i<3;i++){ sqlite3_bind_int(ins,1,i+1); sqlite3_bind_text(ins,2,skus[i],-1,SQLITE_TRANSIENT);
    sqlite3_bind_int(ins,3,prices[i]); sqlite3_step(ins); sqlite3_reset(ins); }
  sqlite3_finalize(ins);
  sqlite3_exec(db,"create index idx_sku on products(sku)",0,0,0);
  sqlite3_stmt *q; sqlite3_prepare_v2(db,"select price from products where sku=?",-1,&q,0);
  sqlite3_bind_text(q,1,"B",-1,SQLITE_TRANSIENT);
  while(sqlite3_step(q)==SQLITE_ROW)
    printf("%d\n", sqlite3_column_int(q,0));
  sqlite3_finalize(q);
  sqlite3_close(db);
  return 0;
}
