CFLAGS ?= -Wall -Wextra -std=c11

futurechain: main.c
	$(CC) $(CFLAGS) -pthread -o futurechain main.c

clean:
	rm -f futurechain

.PHONY: clean
