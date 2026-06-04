CFLAGS ?= -Wall -Wextra -std=c11

onceinit: main.c
	$(CC) $(CFLAGS) -pthread -o onceinit main.c

clean:
	rm -f onceinit

.PHONY: clean
