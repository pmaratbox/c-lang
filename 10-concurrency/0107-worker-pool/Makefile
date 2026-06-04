CFLAGS ?= -Wall -Wextra -std=c11

pool: main.c
	$(CC) $(CFLAGS) -pthread -o pool main.c

clean:
	rm -f pool

.PHONY: clean
