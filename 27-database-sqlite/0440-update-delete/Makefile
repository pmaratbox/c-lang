CFLAGS ?= -Wall -Wextra -std=c11

update-delete: main.c
	$(CC) $(CFLAGS) -o update-delete main.c -lsqlite3

clean:
	rm -f update-delete

.PHONY: clean
