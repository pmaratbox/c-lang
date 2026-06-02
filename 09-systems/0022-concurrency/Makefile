CFLAGS ?= -Wall -Wextra -std=c11 -pthread

concurrency: main.c
	$(CC) $(CFLAGS) -o concurrency main.c

clean:
	rm -f concurrency

.PHONY: clean
