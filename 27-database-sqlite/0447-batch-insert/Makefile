CFLAGS ?= -Wall -Wextra -std=c11

batch-insert: main.c
	$(CC) $(CFLAGS) -o batch-insert main.c -lsqlite3

clean:
	rm -f batch-insert

.PHONY: clean
