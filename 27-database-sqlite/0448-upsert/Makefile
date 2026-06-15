CFLAGS ?= -Wall -Wextra -std=c11

upsert: main.c
	$(CC) $(CFLAGS) -o upsert main.c -lsqlite3

clean:
	rm -f upsert

.PHONY: clean
