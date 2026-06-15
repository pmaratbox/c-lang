CFLAGS ?= -Wall -Wextra -std=c11

create-table-insert: main.c
	$(CC) $(CFLAGS) -o create-table-insert main.c -lsqlite3

clean:
	rm -f create-table-insert

.PHONY: clean
