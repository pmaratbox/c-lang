CFLAGS ?= -Wall -Wextra -std=c11

spawnjoin: main.c
	$(CC) $(CFLAGS) -pthread -o spawnjoin main.c

clean:
	rm -f spawnjoin

.PHONY: clean
