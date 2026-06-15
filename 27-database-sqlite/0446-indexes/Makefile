CFLAGS ?= -Wall -Wextra -std=c11

indexes: main.c
	$(CC) $(CFLAGS) -o indexes main.c -lsqlite3

clean:
	rm -f indexes

.PHONY: clean
