CFLAGS ?= -Wall -Wextra -std=c11

order-by-limit: main.c
	$(CC) $(CFLAGS) -o order-by-limit main.c -lsqlite3

clean:
	rm -f order-by-limit

.PHONY: clean
