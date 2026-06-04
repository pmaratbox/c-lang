CFLAGS ?= -Wall -Wextra -std=c11

parallelmap: main.c
	$(CC) $(CFLAGS) -pthread -o parallelmap main.c

clean:
	rm -f parallelmap

.PHONY: clean
