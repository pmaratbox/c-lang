#include <sqlite3.h>
#include <stdio.h>
int main(void){
  sqlite3 *db; sqlite3_open(":memory:", &db);
  sqlite3_exec(db,"create table users(id integer, name text)",0,0,0);
  sqlite3_exec(db,"create table orders(user_id integer, item text)",0,0,0);
  const int uids[]={1,2};
  const char *names[]={"alice","bob"};
  sqlite3_stmt *iu; sqlite3_prepare_v2(db,"insert into users values(?,?)",-1,&iu,0);
  for(int i=0;i<2;i++){ sqlite3_bind_int(iu,1,uids[i]); sqlite3_bind_text(iu,2,names[i],-1,SQLITE_TRANSIENT);
    sqlite3_step(iu); sqlite3_reset(iu); }
  sqlite3_finalize(iu);
  const int oids[]={1,2,1};
  const char *items[]={"book","pen","lamp"};
  sqlite3_stmt *io; sqlite3_prepare_v2(db,"insert into orders values(?,?)",-1,&io,0);
  for(int i=0;i<3;i++){ sqlite3_bind_int(io,1,oids[i]); sqlite3_bind_text(io,2,items[i],-1,SQLITE_TRANSIENT);
    sqlite3_step(io); sqlite3_reset(io); }
  sqlite3_finalize(io);
  sqlite3_stmt *q; sqlite3_prepare_v2(db,"select u.name,o.item from orders o join users u on u.id=o.user_id order by u.name,o.item",-1,&q,0);
  while(sqlite3_step(q)==SQLITE_ROW)
    printf("%s %s\n", sqlite3_column_text(q,0), sqlite3_column_text(q,1));
  sqlite3_finalize(q);
  sqlite3_close(db);
  return 0;
}
