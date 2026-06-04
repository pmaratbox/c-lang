CFLAGS ?= -Wall -Wextra -std=c11

forkjoinsum: main.c
	$(CC) $(CFLAGS) -pthread -o forkjoinsum main.c

clean:
	rm -f forkjoinsum

.PHONY: clean
