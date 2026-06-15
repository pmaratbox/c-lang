CFLAGS ?= -Wall -Wextra -std=c11

transaction-commit-rollback: main.c
	$(CC) $(CFLAGS) -o transaction-commit-rollback main.c -lsqlite3

clean:
	rm -f transaction-commit-rollback

.PHONY: clean
