CFLAGS ?= -Wall -Wextra -std=c11

connect-and-query: main.c
	$(CC) $(CFLAGS) -o connect-and-query main.c -lsqlite3

clean:
	rm -f connect-and-query

.PHONY: clean
