CFLAGS ?= -Wall -Wextra -std=c11

aggregate-functions: main.c
	$(CC) $(CFLAGS) -o aggregate-functions main.c -lsqlite3

clean:
	rm -f aggregate-functions

.PHONY: clean
