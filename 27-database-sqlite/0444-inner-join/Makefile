CFLAGS ?= -Wall -Wextra -std=c11

inner-join: main.c
	$(CC) $(CFLAGS) -o inner-join main.c -lsqlite3

clean:
	rm -f inner-join

.PHONY: clean
