CFLAGS ?= -Wall -Wextra -std=c11

parameterized-query: main.c
	$(CC) $(CFLAGS) -o parameterized-query main.c -lsqlite3

clean:
	rm -f parameterized-query

.PHONY: clean
